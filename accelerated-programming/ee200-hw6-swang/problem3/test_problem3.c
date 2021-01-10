// standard library
#include <stdio.h>

// problem header file
#include "problem3.h"

void print_hist(unsigned int histogram[26]){
    for (int i=0; i < 26; i++){
        printf("%ld ", histogram[i]);
    }
    printf("\n");
}

void unit_test(const char*str, int len, unsigned int histogram[26]){
    printf("test condition: \n str: %s\n len: %d\n hist[25]=%ld", str, len, histogram[25]);
    printf("\nthe result is \n");
    find_frequency(str, len, histogram);
    print_hist(histogram);
}

void test(){
    unsigned int histogram[26] = {0};
    const char str[] = "!@12ab13cdABCDzz\tZ";
    int len = (sizeof(str) >= 1) ? sizeof(str) - 1 : 0; 
    
    // Null pointer
    unit_test(NULL, len, histogram);
    
    // len > # of element in str
    unit_test(str, len + 3 , histogram);
    
    // negative len value
    unit_test(str, -1 , histogram);
}

int main(int argc, char* argv[]) {
    test();
    return(0);
}

