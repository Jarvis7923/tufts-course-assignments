#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 

#include "problem3.h"


double rand_num() {
  return ((double) rand() / (RAND_MAX)) -1/2.0;
}

Point set_point(){
  Point p;
  double range = 100.0;
  p.x = range * rand_num();
  p.y = range * rand_num();
  return p;
}

void test(){
  srand(time(0));
  for (int i=0; i<2000; i++){

    Triangle t1= {set_point(), set_point(), set_point()};
    Triangle t2= {set_point(), set_point(), set_point()};
    getLarger(&t1,&t2);
    getLarger(&t2,&t1);
  }
  
  Point p1 = {.x=0, .y=0};
  Point p2 = {.x=20, .y=0};
  Point p3 = {.x=0, .y=20};
  

  // regular triangle with positive and negative area 
  Triangle t_neg= {.a=p2, .b=p1, .c=p3}; 
  Triangle t_pos = {.a=p1, .b=p2, .c=p3}; 

  // regular traingle with random area
  Triangle t_rand = {set_point(), set_point(), set_point()};
  
  // abnormal triangle
  Triangle t_point = {.a=p1, .b=p1, .c=p1}; 
  Triangle t_line = {.a=p2, .b=p3, .c=p2}; 
 
  // null pointer

  Triangle* pt_null = NULL; 

  printf("\n\nFor t1 is NULL pointer\":\n");
  getLarger(pt_null, &t_pos);
  printf("\nFor t2 is NULL pointer\":\n");
  getLarger(&t_pos, pt_null);

  // printf("\n\nFor testing \"negtive area of regular triangle\"\n\n");
  // getLarger(&t_neg, &t_pos);
  
  printf("\n\nFor testing \"t1, t2 are regular triangle\"\n#1:\n");
  getLarger(&t_pos,&t_rand);
  printf("#2:\n");
  getLarger(&t_rand,&t_pos);
    
  printf("\n\nFor testing \"t1 is a Line\"\n");
  getLarger(&t_line, &t_pos);
  printf("\nFor testing \"t2 is a Line\"\n");
  getLarger(&t_pos, &t_line);
  
  printf("\n\nFor testing \"t1 is a Point\"\n");
  getLarger(&t_point, &t_pos);
  printf("\nFor testing \"t2 is a Point\"\n\n");
  getLarger(&t_pos, &t_point);

}



int main(int argc, char* argv[])
{

  test();

  return(0);
}

