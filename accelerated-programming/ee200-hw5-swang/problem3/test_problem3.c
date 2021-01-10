#include <stdio.h>
#include "problem3.h"


void unit_test(int* arr, int n) {
    int* pm = find_sequence(arr, n);
    if (pm == NULL) {
        printf("NULL\n");
    }
    else {
        printf("start: %ld for n=%d\n", pm-arr, n);
    }
}

void test(){
    int * arr_null = NULL; 
    printf("null array test\n");
    unit_test(arr_null, 8);

    int arr[] = { 5, 5, 5, 5, 7, 6, 5, 4, 3, 2, 3, 20, 3, 20, 100, 10000 };
    printf("single element\n");
    unit_test(arr, 1);
    
    printf("element with same value\n");
    unit_test(arr, 4);
    
    printf("regular test, max in the middle\n");
    unit_test(arr, 12);
    
    printf("regular test, max at the end\n");
    unit_test(arr, 16);
    
    printf("decrease seq\n");
    unit_test(arr+4, 5);

    printf("increasing\n");
    unit_test(arr+9, 3);

    printf("short test\n");
    unit_test(arr+11, 3);

}


int main(int argc, char* argv[])
{

    // Put anything here that you think is appropriate to test your function
    test();
    return(0);
}

