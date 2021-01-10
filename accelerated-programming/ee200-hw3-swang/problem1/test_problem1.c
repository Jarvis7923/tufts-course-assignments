#include <stdio.h>
#include "problem1.h"

// printing the result of `print_factor` to the screen 
void unit_test(int d){
    printf("result for %d is: \n", d);
    int res = print_factors(d);
    if (res == -1) {
        printf("-1\n");
    }
}

// testing the function `print_factors` for -3 to 25
void test() {
    for(int i=-3; i < 25; i++){
        unit_test(i);
    }
}

int main(int argc, char* argv[]) {

    test();

    return(0);
}

