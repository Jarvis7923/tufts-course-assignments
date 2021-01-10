# Resources
You should fill in this section with the resources that you used to develop your code.  You don't need to include the teaching staff or the textbook, but you should list anyone you worked with, and any online or paper resources you used.

# Overview
This assignment requires writing a complete class utilizing many of the object-oriented features of C++.  You'll also need to work with `malloc` and `free` to carefully manage memory.  Be sure to use Valgrind at some point in your testing, since OOP features in C++ make it very easy to leak memory.

Since you're writing C++ code, you'll need to compile with `g++` rather than `gcc`.
You don't need to submit a Makefile, but we suggest writing one to make your life easier.

Like previous assignments, you'll need to write you own test code.  To the extent possible, you should test each function individually, rather than in one monolithic test.  This ensures that errors in one function don't get masked by errors in other functions.

# Submission
Your code should be pushed to Github, and then you should submit to Gradescope from there.  You will not be able to upload files directly.

# Problem

Write a class called `Array` representing a 1D array of integers, which makes up for some of the deficiencies of traditional C arrays.  Your class should have the functionality below:

* The function `initialize(int size, int val)` should set up the Array with storage for `size` elements, all initialized to `val`.
* The function `cleanup()` should free all `malloc`ed memory associated with the Array.

* `size()` returns the current size of the `Array`.
* The function `append(int x)` should add the element `x` to the end of the array.
* The function `append(Array y)` should add all of the contents of Array `y` to the end of the array.

* Assigning one Array to another should make a *deep copy* of the Array.  For example, after doing

    b = a; // b and a already exist

The Array `b` should be a copy of `a`, but with its own memory allocated, such that modifying `b` does not change `a`.  *Note that you won't be able to do*

    Array b = a; // We're just now declaring b

*because this requires a copy constructor, which we'll learn about next Monday.*

* A user should be able to read and write elements of the `Array` using bracket notation, just like a standard C array.

    arr[3] = 5;
    int x = arr[0];

If any index is invalid, your code should print a string with the word "error" and exit with the status 0.  *This is not a good way to handle errors, and we'll learn better ways of handling these kinds of errors soon.*

These functions should be public; all implementation details of your class should be private.

Your code should manage memory with `malloc` (or one of its derivates like `calloc`) and `free`.  We'll learn the C++ ways of managing memory soon.

