/* @Author
 
 * Student Name: Mehmet Yakuphan Bilgiç
 * Student ID : 150170703
 * Date: 08.11.2018 */

#include <stdio.h>
#include <fstream>
#include <iostream>
#include "language_model.h"

using namespace std;

void language_model::readData(const char * fileName){
    ifstream inputFile(fileName);
    string line;
    
    while(inputFile) {
        getline(inputFile, line);
        
        for(int i = 0; i < line.size(); i++) {
            if(line.at(i) >= 'A' && line.at(i) <= 'Z') {        // handling capital letters, making them small
                vocabularylist->add_char(line.at(i) + 32);      // before adding them
            }
            else if((int)line.at(i) == 13) {
                
            }
            else {                                              // else
                vocabularylist->add_char(line.at(i));
            }
        }
    }
    
    vocabularylist->sort();                                     // sorting list after finishing first read.
    
    ifstream inputFile2(fileName);
    string line2;
    
    while(inputFile2) {                                         // reading the file again
        getline(inputFile2, line2);
        
        if(line2.size() != 0){
            for(int i = 0; i < line2.size() - 1; i++) {
                if(line2.at(i) >= 'A' && line2.at(i) <= 'Z') {        // handling capital letters
                    if(line2.at(i+1) >= 'A' && line2.at(i+1) <= 'Z') {
                        vocabularylist->add_occurence(line2.at(i) + 32, line2.at(i+1) + 32);
                    }
                    else {
                        vocabularylist->add_occurence(line2.at(i) + 32, line2.at(i+1));
                    }
                }
                else if((int)line2.at(i) == 13) {
                    
                }
                else {                                              // handling small letters
                    if(line2.at(i+1) >= 'A' && line2.at(i+1) <= 'Z') {
                        vocabularylist->add_occurence(line2.at(i), line2.at(i+1) + 32);
                    }
                    else {
                        vocabularylist->add_occurence(line2.at(i), line2.at(i+1));
                    }
                }
            }
        }
    }
}

double language_model::calculateProbability(const char* first,const char* second){
    char *space = "<SP>";
    char correctedArg = (char) 32;
    const char *temp = &correctedArg;
    double result;
    
    if(strncmp(second, space, 2) == 0){
        result = vocabularylist->get_union_occurence(first, temp) /(double) vocabularylist->get_occurence(first);
    }
    else if(strncmp(first, space, 2) == 0) {
        result = vocabularylist->get_union_occurence(temp, second) /(double) vocabularylist->get_occurence(temp);
    }
    else {
        result = vocabularylist->get_union_occurence(first, second) /(double) vocabularylist->get_occurence(first);
    }
    
    return result;
}
