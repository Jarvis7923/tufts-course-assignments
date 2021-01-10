#include <stdio.h>
#include "problem3.h"
#include <math.h>

// void print_point(Point p) {
//   printf("x: %f, y: %f\n", p.x, p.y);
// }

// get the area of the triangle T
double getArea(Triangle* t) {
  Point a = t->a; 
  Point b = t->b; 
  Point c = t->c; 
  
 // print_point(a);
 // print_point(b);
 // print_point(c);

  double A = (a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y))/2.0;
 
  // if (A < 0.0) {
  //   printf("----negative area----\n");
  //   return -A;
  // }
  // else{
  //   printf("----positive area----\n");
  //   return A;
  // }
 return fabs(A);
}


Triangle* getLarger(Triangle* first, Triangle* second)
{
  if (second == NULL) {
    printf("first: 0\n");
    return first;
  }
  if (first == NULL) {
    printf("second: 0\n");
    return second;
  }
  
  double af = getArea(first);
  double as = getArea(second);
  
  printf("A1 is %lf; A2 is %lf\n", af, as);

  if (af < 1e-5) {
     printf("second: 1\n");
     return second;
  }

  if (af > as - 1e-5){
    printf("first: 1\n");
    return first;
  }
  else {
    printf("second: 2\n");
    return second; 
  }
}

