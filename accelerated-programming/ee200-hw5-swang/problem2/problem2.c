#include <stdio.h>
#include "problem2.h"


int* find_min(int* array, int n)
{

    if (array == NULL || n < 1) {
        return NULL;
    }

    int offset = 0; 
    int min = array[0];

    for(int i=1; i<n; i++){
        if (array[i] < min){
            min = array[i];
            offset = i;
        }
    }
    return array + offset;
}

