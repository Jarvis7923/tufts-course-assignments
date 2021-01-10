#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 
#include "problem4.h"


// generate a random number 
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

    // srand(time(NULL));
    // for (int i=0; i<20; i++) {
    //     Triangle t1= {set_point(), set_point(), set_point()};
    //     Triangle t2= {set_point(), set_point(), set_point()};
    //     getLarger(t1,t2);
    //     getLarger(t2,t1);
    // }
    Point p1 = {.x=0, .y=0};
    Point p2 = {.x=1, .y=0};
    Point p3 = {.x=0, .y=1};
    Point p4 = {.x=10, .y=10};
    
    // other test 
    Triangle t0 = {.a=p2, .b=p1, .c=p3};
    Triangle t1 = {.a=p2, .b=p3, .c=p2};
    Triangle t2 = {.a=p1, .b=p2, .c=p3};
    Triangle t3 = {.a=p1, .b=p1, .c=p1};
    Triangle t4 = {.a=p1, .b=p2, .c=p4};

    getLarger(t0,t2);

    getLarger(t2,t4);
    getLarger(t4,t2);

    // t1 is a line 
    getLarger(t1,t2);
    getLarger(t2,t1);

    // t1 is a point 
    getLarger(t3,t2);
    getLarger(t2,t3);

}

int main(int argc, char* argv[]) {

    test();

    return(0);
}

