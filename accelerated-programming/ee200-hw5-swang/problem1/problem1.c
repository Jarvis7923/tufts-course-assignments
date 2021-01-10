#include <stdio.h>
#include <stdlib.h>

#include "problem1.h"


void linspace(double* array, double min, double max, int n)
{
    // handle the abnormal inputs 
    if  (array == NULL){
        printf("NULL array is given\n");
        return ;
    }
    if (n < 1){
        array = NULL;
        printf("n < 1\n");
    }
   //  else if (n == 1) {
   //      array[0] = min;
   //      printf("n = 1\n");
   //  }
    else {
        double interval = (max - min)/(n - 1.0);
        array[0] = min;
        for (int i=1; i<n; i++){
            array[i] = array[i-1]+interval;
        }
        printf("n >= 1\n");
    }

}

