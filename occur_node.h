/* @Author
 
 * Student Name: Mehmet Yakuphan Bilgiç
 * Student ID : 150170703
 * Date: 08.11.2018 */

#ifndef occur_node_h
#define occur_node_h

struct occur_node {
    char character;
    occur_node *next;
    int occurence = 0;
};

#endif /* occur_node_h */
