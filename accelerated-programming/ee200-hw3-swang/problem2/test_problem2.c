#include<stdio.h>
#include "problem2.h"

// adding prompts for the `find_power` function
void unit_test(int d) {
    int result = find_power(d);
    printf("for %d: return %d\n", d, result);
}

// test function that feed integers ranging 
// from -20 to 20, and the max 32bit int number 
// to the `fincd_power`
void test() {
    for (int i=-20; i<20; i++){
        unit_test(i);
    }
    unit_test(2147483647);
}

int main(int argc, char* argv[])
{
    test();

    return(0);
}

