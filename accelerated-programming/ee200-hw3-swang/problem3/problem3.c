#include <math.h>
#include <stdio.h>

#include "problem3.h"

// calculator function for `3 + 4` 
double calculate(double x, char operation, double y) {
    double r;
    switch (operation) {
        case '+':
            return (x + y);

        case '-':
            return (x - y);

        case '*':
            return (x * y);

        case '/':
            if (y < 1e-7 && y > -1e-7){
                printf("error");
                return 0;
            }
            return (x / y);

        case '^':
            return (pow(x,y));
        default: 
            printf("error");
            return 0;
    }

    return 0; 
}

