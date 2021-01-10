#include <stdio.h>
#include "problem3.h"


int* find_sequence(int* seq, int n) {

    if (n < 2 || seq == NULL) {
        return NULL;
    }

    // max length of the incremental sequence in seq
    int max = 0;
    // current length of the incremental sequence in seq
    int cur = 1;
    // start of the current incremental seq
    int *p = seq;
    // pointing at the startof the last incremental seq
    int *last = seq;

    for(int i = 1; i < n; i++) {
        // check if the value is increasing
        if(seq[i] > seq[i-1]) cur ++;
        else {
            // record the max length of the subseq if the value is not increasing any more
            if(cur > max) {
                max = cur;
                last = p;
            }
            // set p point at the current element
            p = seq + i;
            cur = 1;
        }
    }
    // check if the current or the max incremental sequence length is less than 2. 
    if (max < 2 && cur < 2)  return NULL;
    // check if the len of the last incremental seq is larger 
    return cur < max ?  last :  p; 
}

