/* @Author
 
 * Student Name: Mehmet Yakuphan Bilgiç
 * Student ID : 150170703
 * Date: 08.11.2018 */

#ifndef vocab_node_h
#define vocab_node_h
#include "occur_node.h"

struct vocab_node {
    char character;
    vocab_node *next;
    occur_node *list = NULL;
};

#endif /* vocab_node_h */
