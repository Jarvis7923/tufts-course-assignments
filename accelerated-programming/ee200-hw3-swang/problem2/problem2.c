
#include "problem2.h"


// find the max power of 2 that is less than `n`
int find_power(int n) {
    int a = 1;
    if (n == a) {
        return 1;
    }
    else if (n > a) {
        while (a <= n/2) {
            a *= 2;
        }
        return a;
    }
    return 0; 
}

