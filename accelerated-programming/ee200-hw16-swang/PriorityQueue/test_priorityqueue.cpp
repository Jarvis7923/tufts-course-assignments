#include "priorityqueue.h"
#include <cstdio>
#include <stdexcept>
#include <iostream>

int main(int argc, char* argv[])
{
  // Here's some quick test code to get you started.  You'll need much more
  // thorough testing, of course.

  PriorityQueue<int> q;
  
  try {
    q.top();
  }
  catch (std::out_of_range & ex) {
        std::cout << ex.what();
  }
  // Push three elements onto the front
  q.push(1);
  q.push(2);
  q.push(3);
  
  // Make a copy
  PriorityQueue<int> another = q;

  // Push some more elements onto the front of the original
  q.push(4);
  q.push(5);


  while(q.size() > 0){
    printf("%d ", q.top());
    q.pop();
  }
  printf("\n");

  while(another.size() > 0){
    printf("%d ", another.top());
    another.pop();
  }
  printf("\n");
  
  // Make a copy
  PriorityQueue<std::string> q2;

  q2.push("abc");
  q2.push("Abc");
  q2.push("abcdefg");

  while(q2.size() > 0){
    std::cout<< q2.top() << " ";
    q2.pop();
  }
  printf("\n");

  return(0);
}

