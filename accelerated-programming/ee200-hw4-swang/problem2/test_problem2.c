#include <stdio.h>
#include "problem2.h"

void test_weekday(){
    for (int i = 0; i < 8; i++) {
        time_t tweekday = 60*60*24*i; 
        print_time(tweekday);
    }
}

void test_month(){
    for (int i = 0; i < 13; i++) {
        time_t tmonth = 31*60*60*24*i; 
        print_time(tmonth);
    }
}

void test() {
    unsigned int l[] = {
        1548088343,
        1549088343
    };
    test_weekday();
    test_month();
    printf("\ntest cases\n"); 

    for(int i = 0; i<2; i++){
        print_time(l[i]);
    }

}

int main(int argc, char* argv[])
{

    // Put anything here that you think is appropriate to test your function
    // e.g, print_time(10);

    // print_time(10);
    test();

    return(0);
}

