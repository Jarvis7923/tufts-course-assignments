// standard library
#include <stdio.h>

// problem header file
#include "problem3.h"

void find_frequency(const char* str, int len, unsigned int histogram[26]) {
    // make sure all the elements in histogram is zero
    unsigned int * ph = histogram;
    for(int i = 0; i < 26; i++) {
        *(ph + i) = 0;
    }
    
    // check if str is null or len is <= 0 
    if (str == NULL || len <=  0) 
        return;

    // histogram function 
    for(int i = 0; i < len; i++) {
        // check if str has ended
        if (*(str + i) == '\0' ) 
            break;

        for (int j = 0 ; j < 26; j++) {
            if (*(str + i) == 'A' + j || *(str + i) == 'a' + j){
                *(ph + j) = *(ph + j) + 1;
                break;
            }
        }
    }
}
