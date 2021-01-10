// standard libraries
#include <stdio.h>

// header file of the problem
#include "problem2.h"

// testing function 
void unit_test(char* str){
    printf("\ntesting string is %s\n", str);
    lower(str);
    printf("lower(str) result = %s\n", str);
}

void test(){
    // NULL pointer testing case
    unit_test(NULL);
    
    // test case with "!"
    char rs[] = "HELLO!";
    unit_test(rs);
    
    // test case contains special chars
    char ns[] = "123456789abcd\n\t\\";
    unit_test(ns);
}

// main function
int main(int argc, char* argv[]) {
    // test function
    test();

    return(0);
}

