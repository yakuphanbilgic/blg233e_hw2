/* @Author
 
 * Student Name: Mehmet Yakuphan Bilgiç
 * Student ID : 150170703
 * Date: 08.11.2018 */

#ifndef language_model_h
#define language_model_h
#include "vocab_list.h"

struct language_model {
    vocab_list *vocabularylist = new vocab_list;
    void readData (const char *);
    double calculateProbability (const char* first, const char* second);
};

#endif /* language_model_h */
