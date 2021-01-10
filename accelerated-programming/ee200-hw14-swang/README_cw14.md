# Resources
You should fill in this section with the resources that you used to develop your code.  You don't need to include the teaching staff or the textbook, but you should list anyone you worked with, and any online or paper resources you used.

# Overview
This assignment is similar to the series of Array-class assignments: you'll be building and testing a complete class which implements a data structure.  There's a lot to think about all at once: constructors, templates, pointers, etc.  It might help to tackle one part a time, and build up the class in steps the way you created the Array class.

# Submission
Your code should be pushed to Github, and then you should submit to Gradescope from there.  You will not be able to upload files directly.

# Problem

Write a class called `LinkedList` which implements a templated linked list.  Your class should have the functionality below:

* A default constructor, which takes no arguments
* Constructor which takes the length and a pointer to an array to initialize the elements: `LinkedList(int length, T* values)`.  You may assume that if the pointer is not NULL, it points to a valid array that holds at least `length` elements.  The LinkedList should create its own copy of the data.
* Copy constructor, which creates a deep copy of the `LinkedList`.
* Destructor which cleans up any memory associated with the `LinkedList`.

* `size()` returns the current size of the `LinkedList`.
* `getItem(int n)` returns the n-th item in the `LinkedList`.
* The function `insert(T x, int pos)` should insert the element `x` into the list at position `pos`.  Position 0 corresponds to the beginning of the list (before the first item), position `size()` would be after the last element.  Calling `getItem(pos)` should retrieve the newly-inserted element.
* The function `remove(int pos)` should remove the n-th item in the LinkedList.

* Assigning one LinkedList to another should make a deep copy of the LinkedList.

These functions should be public; all implementation details of your class should be private.

As always, your code should be Valgrind-clean.  Memory leaks and out-of-bounds accesses are easy to do with linked lists, so Valgrind is your friend!

