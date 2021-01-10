// standard library
#include <stdio.h>
#include <limits.h>

// problem header
#include "problem4.h"


const char* find_shortest(const char * const * strings, int len) {
    // check the NULL pointer
    if(strings == NULL) return NULL;

    const char* res = NULL;
    const char* cur = NULL; 
    
    unsigned int min = UINT_MAX;
    unsigned int slen;

    // check if one of the string is NULL
    for(int i=0;  i<len ; i++) {
        if (*(strings+i) == NULL ) continue;
        cur  =  *(strings+i);
        slen = 0;
        while( *(cur) != '\0') {
            cur++;
            slen++;
        }
        if(slen < min) {
            res = *(strings+i);
            min = slen;
        }
    }
    return res;
}
