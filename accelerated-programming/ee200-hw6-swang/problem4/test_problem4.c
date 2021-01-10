// standard library
#include <stdio.h>

// problem header
#include "problem4.h"

// helper function to print strings
void print_strings(const char * const * strings, int len){
    for(int i=0;  i<len; i++) {
        printf("%d:  %s\n", i, *(strings+i));
    }
}

// single test
void unit_test(const char * const * strings, int len) {
    printf("\ntest case:\n");
    print_strings(strings, len);
    printf("the shortest: %s\n", find_shortest(strings, len) );   
}

// test scenario
void test() {
    // NULL pointer case
    const char * const * s0 = NULL; 
    // empty string case
    const char * s1[] = {"apple", "i","swords", ""}; 
    // special char
    const char * s2[] = {"!$3","i_i","\ta","swords", "rei na"};
    // multiple shortest string
    const char * s3[] = {"00","01","02","03"};
    // Null string case
    const char * s4[] = {NULL, "apple", "i","swords"}; 

    const char * const * string_arr[] = {s0, s1, s2, s3, s4};

    int plen = sizeof(string_arr) / sizeof(string_arr[0]);
    int lens[10] = {0, 4, 5, 4, 5};

    for(int i = 0; i < plen; i++) {
        unit_test(string_arr[i], lens[i]);
    }
}

// main function
int main(int argc, char* argv[]) {
    test();   
    return(0);
}

