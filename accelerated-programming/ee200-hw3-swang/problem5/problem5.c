
#include "problem5.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_random(int n, int max)
{
 unsigned int seed = time(0);
 srand(seed);
 for (int i=0; i<n; i++) {
   printf("%d ", rand()%max);
 }
}

