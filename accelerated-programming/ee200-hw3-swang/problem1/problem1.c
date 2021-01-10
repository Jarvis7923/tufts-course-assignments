#include<stdio.h>
#include "problem1.h"

int print_factors(int n){
    // function for printing the factors 
    // of `n` in increasing order
    
    if (n < 2) {
        return (-1);
    }
    for (int i=2; i<=n; i++) {
        if (n % i == 0) {
            printf("%d ", i);
            n = n/i;
            i--; 
        }
    }
    printf("\n");

    return(0); 
}

