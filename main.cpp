/* @Author
 
 * Student Name: Mehmet Yakuphan Bilgiç
 * Student ID : 150170703
 * Date: 08.11.2018 */

#include <iostream>
#include "language_model.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    language_model lm;                      // creates a language model instance
    lm.readData(argv[1]);                   // reads data from file, given as arguments
    
    const char* first = argv[2];            // if there are multiple arguments, print calculate probability
    const char* second = argv[3];
    
    if(argv[2] == NULL){
        lm.vocabularylist->print();         // if there is only one argument, print list
    }
    else {
        cout << lm.calculateProbability(first, second) << endl;
    }
       
    return 0;
}
