/* @Author
 
 * Student Name: Mehmet Yakuphan Bilgiç
 * Student ID : 150170703
 * Date: 08.11.2018 */

#ifndef vocab_list_h
#define vocab_list_h
#include "vocab_node.h"

struct vocab_list {
    vocab_node *head;
    vocab_list();
    void print();
    void sort();
    void add_char(char );
    void add_occurence(char , char );
    int get_occurence(const char* );
    int get_union_occurence (const char* ,const char* );
};

#endif /* vocab_list_h */
