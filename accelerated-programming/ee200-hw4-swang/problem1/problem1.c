#include <stdio.h>

#include <math.h>


double calculate(double x, char operation, double y) {
    switch (operation) {
        case '+':
            return (x + y);

        case '-':
            return (x - y);

        case '*':
            return (x * y);

        case '/':
            if (y < 1e-10 && y > -1e-10){
                printf("error");
                return (0);
            }
            return (x / y);

        case '^':
            return (pow(x,y));

        default: 
            printf("error");
            return (0);
    }

    return(0); 
}


int main(int argc, char* argv[]) {

    double x, y;
    char c;
    if (scanf("%lf %c %lf", &x, &c,&y)!= 3 ){
        printf("error");
    }
    else{
        double res = calculate(x,c,y);
        printf("%.10lf\n", res);
    }
    // printf("scanf return value is %d\n", scanf("%lf %c %lf", &x, &c,&y));

    // printf("\nprint:\n%lf %c %lf = %lf\n",x,c,y, calculate(x,c,y));

    return(0);
}

