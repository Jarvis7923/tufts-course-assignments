#include <stdio.h>
#include <math.h>

#include "problem4.h"

// get the euclidean distance of the point a and point b
// double dist(Point a, Point b){
//     double res = pow(a.x-b.x,2)+pow(a.y-b.y, 2);
//     return sqrt(res); 
// }

// get the area of the triangle T
double getArea(Triangle t) {
    Point a = t.a; 
    Point b = t.b; 
    Point c = t.c; 

    // double x = dist(a,b);
    // double y = dist(a,c);
    // double z = dist(b,c);

    // if (x < 1e-5 || y < 1e-5 || z < 1e-5){
    //     printf("not a triangle\n");
    //     return -1;
    // }
    // double p = (x+y+z)/2.0;


    // double A = sqrt(p*(p-x)*(p-y)*(p-z));
    double A = fabs((a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y))/2.0);

    // if (A < 0.0) {
    //   A = (-A);
    // }
    printf("the area is %f\n", A);
    return A;
}

Triangle getLarger(Triangle first, Triangle second) {
    double  af = getArea(first);
    double  as = getArea(second);

    // if (af < 1e-7) {
    //     printf("second: 0\n");
    //     return second;
    // }
    if (af > as - 1e-10 ){
        printf("first: 0\n");
        return first; 
    }
    else{
        printf("second: 1\n");
        return second;
    }
}

