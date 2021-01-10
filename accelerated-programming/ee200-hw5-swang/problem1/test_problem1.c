#include <stdio.h>
#include <stdlib.h>

#include "problem1.h"

// helper function to 

void print_array(double* arr, int n ){
    // print array with size of n. eg. `{ 1 2 3 }`
    // assume: 
    //   1. the length of the array is postive
    //   2. n is smaller than or equal to length of array 

    if (n < 1){
        printf("invalid n %d\n", n);
    }
    else {
        printf("{ ");
        for(int i=0; i<n; i++){
            printf("%lf ", *(arr+i));
        }
        printf("}\n");
    }
}

void test() {
    // 

    double arr[1000] = {0};

    double min = 1;
    double max = 3;
    
    double* arr_null = NULL;
    linspace(arr_null, min, max, 10); 

    for (int n=-1; n < 10; n++){
        linspace(arr, min, max, n);
        print_array(arr, n);
    }

}


int main(int argc, char* argv[]) {

    test();

    return(0);
}

