#include "linkedlist.h"
#include <cstdio>

int main(int argc, char* argv[])
{
    // Here's some quick test code to get you started.  You'll need much more
    // thorough testing, of course.

    LinkedList<int> list;

    // Push three elements onto the front
    list.insert(1, 0);
    list.insert(2, 0);
    list.insert(3, 0);

    // Make a copy
    LinkedList<int> another = list;

    // Push some more elements onto the front of the original
    list.insert(4, 0);
    list.insert(5, 0);

    for(int i = 0; i < list.size(); i++){
        printf(" list[%d] = %d\n", i, list.getItem(i));
    }

    for(int i = 0; i < another.size(); i++){
        printf("another[%d] = %d\n", i, another.getItem(i));
    }

    return(0);
}

