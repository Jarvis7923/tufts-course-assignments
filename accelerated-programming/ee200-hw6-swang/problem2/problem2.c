// standard libraries
#include <stdio.h>

// header file of the problem
#include "problem2.h"

// recursive to_lower_case fucntion
void lower(char* str) {
    if (str != NULL && *str != '\0'){
        if (*str >= 'A' && *str <= 'Z' ){
            *str += 32;
        }
        lower(str+1);
    }
}
