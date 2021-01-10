# Resources
You should fill in this section with the resources that you used to develop your code.  You don't need to include the teaching staff or the textbook, but you should list anyone you worked with, and any online or paper resources you used.

# Overview
Like the Array and LinkedList assignments, your task is to build a priority queue class using a heap as the underlying data structure.  Hopefully this is a little simpler, since there are fewer methods to implement, and you don't have to manage memory.

# Submission
Your code should be pushed to Github, and then you should submit to Gradescope from there.  You will not be able to upload files directly.

# Problem

Write a class called `PriorityQueue` which uses a max-heap to implement a priority queue.  It should be templated, and work with any object type which implements the comparison operators (<, >, ==, and !=).  Your class should have the functionality below:

* A default constructor, which takes no arguments
* Copy constructor, which creates a deep copy of the `PriorityQueue`.
* Destructor which cleans up any memory associated with the `PriorityQueue`.
* Assigning one PriorityQueue to another should make a deep copy of the PriorityQueue.

* `int size()` returns the current number of elements in the `PriorityQueue`.
* `T top()` returns the first (highest value) item in the `PriorityQueue`.
* `void push(T x)` should add the element `x` to the `PriorityQueue`.
* `void pop()` should remove the top item in the PriorityQueue.

These functions should be public; all implementation details of your class should be private.  You are welcome to use std::vector or your Array class to store the values, but you need to implement the heap/queue yourself (i.e., you can't just call std::priority_queue ;-) ).

As always, your code should be Valgrind-clean.

