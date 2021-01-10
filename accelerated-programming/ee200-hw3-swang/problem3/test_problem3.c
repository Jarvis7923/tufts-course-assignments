#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "problem3.h"

double f_rand(double max) {
    return max*((float)rand()/(float)RAND_MAX - 1.0/2.0);
}

// unit test for all the operations in the calculator
void unit_test(double a, double b) {
    char c[6] = {'+','-','*','/','^','d'};
    for (int i=0; i<6; i++){
        printf("%f %c %f = %f\n", a, c[i], b, calculate(a, c[i], b));
    }
}

// testing 100 time for random number 
void test() {
    srand(time(NULL));
    for (int i=0; i<10; i++){
        // unit_test(4, 2);
        unit_test(f_rand(10), f_rand(10));
    }
    unit_test(f_rand(10), 0);
}


int main(int argc, char* argv[]) {

    test();

    return(0);
}

