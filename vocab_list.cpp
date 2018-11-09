/* @Author
 
 * Student Name: Mehmet Yakuphan Bilgiç
 * Student ID : 150170703
 * Date: 08.11.2018 */

#include <stdio.h>
#include <iostream>
#include "vocab_list.h"

using namespace std;

vocab_list::vocab_list() {                          // Using constructor to create a list
    head = NULL;
}

void vocab_list::print(){                           // prints every character added to the list
    vocab_node *printNode = new vocab_node;         // and prints their occurences with occurence numbers.
    printNode = head;
    
    occur_node *occurPrint = new occur_node;
    
    while(printNode != NULL) {
        if(printNode->list != NULL){
            occurPrint = printNode->list;
            
            if(printNode->character + 'A' == 'a') {
                cout << "character SP: " << endl;
            }
            else if((int) printNode->character <= 31){
        
            }
            else {
                cout << "character " << printNode->character << ":" << endl;
            }
            
            while(occurPrint != NULL){
                if(occurPrint->character + 'A' == 'N') {
                    
                }
                else if(occurPrint->character + 'A' == 'a') {
                    cout << "   " <<  "<SP, " << occurPrint->occurence << ">" << endl;
                }
                else{
                    cout << "   " <<  "<" << occurPrint->character << ", " << occurPrint->occurence << ">" << endl;
                }
                occurPrint = occurPrint->next;
            }
        }
        printNode = printNode->next;
    }
    cout << endl;
}

void vocab_list::sort(){                                // implements a bubble sort algorithm in list
    vocab_node *currentNode = new vocab_node;
    vocab_node *previousNode = new vocab_node;
    vocab_node *tempNode = new vocab_node;
    vocab_node *lastNode = new vocab_node;
    
    currentNode = head->next;
    previousNode = head;
    
    while(currentNode->next != NULL) {
        if(currentNode->next->character < previousNode->next->character){
            previousNode->next = currentNode->next;
            currentNode->next = currentNode->next->next;
            previousNode->next->next = currentNode;
            
            previousNode = head;
            currentNode = head->next;
        }
        else {
            previousNode = previousNode->next;
            currentNode = currentNode->next;
        }
    }
    
                                                        // sorting the head node since it is an edge case
    currentNode = head;                                 // and previous loop did not consider sorting it.
    tempNode = head->next;
    
    while(currentNode->next != NULL) {
        if(currentNode->next->character > head->character) {
            head->next = currentNode->next;
            currentNode->next = head;
            head = tempNode;
            break;
        }
        else {
            currentNode = currentNode->next;
        }
    }
    
                                                        // previously sorted using ascii values,
    currentNode = head;                                 // so special characters are coming first,
    tempNode = head;                                    // following part moves the special characters to the end of the list
    
    while(currentNode->next != NULL){
        if(currentNode->next->character >= 'a'){
            head = currentNode->next;
            currentNode->next = NULL;
            break;
        }
        currentNode = currentNode->next;
    }
    
    lastNode = head;
    
    while(lastNode->next != NULL) {
        lastNode = lastNode->next;
    }
        
    lastNode->next = tempNode;
}

void vocab_list::add_char(char c){            // adds elements to the list if they are unique to the
    vocab_node *newNode = new vocab_node;     // end of the list
    
    newNode->character = c;                   // assign node's character
    
    vocab_node *tempHead = new vocab_node;    // create a head temp
    tempHead = head;
    
    if(head == NULL){                         // if it is first element in the list
        newNode->next = NULL;
        head = newNode;
    }
    else if(head->next == NULL){              // if there is only one element on the list
        if(tempHead->character > c){          // c becomes after the element
            head->next = newNode;
            newNode->next = NULL;
        }
        else{                                 // c becomes before the element
            newNode->next = head;
            head = newNode;
        }
    }
    else {                                    // there are elements on the list. So place
        tempHead = head;                      // if it is unique
        bool unique = true;
        
        while(tempHead->next != NULL){
            if(tempHead->character == c){
                unique = false;
                break;
            }
            else{
                tempHead = tempHead->next;
            }
        }
        if(unique) {
            newNode->next = head->next;
            head->next = newNode;
        }
    }
}

void vocab_list::add_occurence(char first, char second) {
    vocab_node *vocabTraverse = new vocab_node;
    occur_node *occurTraverse = new occur_node;
    
        // node to be added
    occur_node *addThis = new occur_node;
    addThis->character = second;
    addThis->occurence = 1;
    
    vocabTraverse = head;
    
    while(vocabTraverse != NULL) {                          // finds the node that has first char as it's
        if(vocabTraverse->character == first){
            occurTraverse = vocabTraverse->list;
            bool flag = false;
            
            while(occurTraverse != NULL){
                if(occurTraverse->character == second){     // if occurence node already exists, increase it
                    occurTraverse->occurence = occurTraverse->occurence + 1;
                    flag = true;
                    break;
                }
                occurTraverse = occurTraverse->next;
            }
            
            if(flag == true) {
                break;
            }
            if(flag == false){                              // if it doesnt exist, create a new one
                if(vocabTraverse->list == NULL){
                    vocabTraverse->list = addThis;
                    break;
                }
                else if(vocabTraverse->list->next == NULL){
                    vocabTraverse->list->next = addThis;
                    break;
                }
                else {
                    addThis->next = vocabTraverse->list;
                    vocabTraverse->list = addThis;
                    break;
                }
            }
        }
        vocabTraverse = vocabTraverse->next;
    }
}

int vocab_list::get_occurence(const char* c) {
    vocab_node *vocabTraverse = new vocab_node;
    occur_node *occurTraverse = new occur_node;
    int occurenceCount = 0;
    
    vocabTraverse = head;
    
    while(vocabTraverse != NULL) {                          // find the node with the desired char
        if(vocabTraverse->character == *c){
            occurTraverse = vocabTraverse->list;
            while(occurTraverse != NULL){
                occurenceCount += occurTraverse->occurence; // sum it's occurences, return it
                occurTraverse = occurTraverse->next;
            }
        }
        vocabTraverse = vocabTraverse->next;
    }
    
    return occurenceCount;
}

int vocab_list::get_union_occurence(const char* first,const char* second) {
    vocab_node *vocabTraverse = new vocab_node;
    occur_node *occurTraverse = new occur_node;
    int unionOccurenceCount = 0;
    
    vocabTraverse = head;
    
    
    
    while (vocabTraverse != NULL){
        if(vocabTraverse->character == *first){             // find the node with first character as it's character
            occurTraverse = vocabTraverse->list;
            while (occurTraverse != NULL){
                if(occurTraverse->character == *second){
                    unionOccurenceCount = occurTraverse->occurence;
                    break;                                  // find the second character in first characters occurence
                }
                occurTraverse = occurTraverse->next;
            }
        }
        vocabTraverse = vocabTraverse->next;
    }
    
    return unionOccurenceCount;                             // return the occurence count
}
