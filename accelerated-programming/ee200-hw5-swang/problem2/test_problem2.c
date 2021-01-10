#include "stdio.h"
#include "problem2.h"

void unit_test(int* arr, int n) {
    int* pm = find_min(arr, n);
    if (pm == NULL) {
        printf("NULL" );
    }
    else {
        printf("min: %d for n=%d\n", *pm, n);
    }
}

void test(){

    int* a_null = NULL;
    unit_test(a_null, 10);

    int a[] = {6,3,1,4,2,-1};

    for(int n=-1; n < 7; n++){
        unit_test(a, n);
    }


}

int main(int argc, char* argv[])
{
    // Put anything here that you think is appropriate to test your function
    test();
    return(0);
}

