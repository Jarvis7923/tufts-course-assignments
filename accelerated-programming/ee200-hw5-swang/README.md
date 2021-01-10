# Resources
You should fill in this section with the resources that you used to develop your code.  You don't need to include the teaching staff or the textbook, but you should list anyone you worked with, and any online or paper resources you used.

# Overview
This classwork set is very similar to the previous ones; you'll be writing functions which perform particular operations.

# Submission
You should commit and push your code to GitHub when you reach any significant milestone (you finish a problem, or get a function tested and working).
When you are finished, submit your code on Gradescope via Github.

# Problems

## 1. linspace
Write the function

    void linspace(double * array, double min, double max, int n)

which fills in an array with a set of linearly-spaced values from min to max, inclusive.
Your function should behave like the [MATLAB linspace function](https://www.mathworks.com/help/matlab/ref/linspace.html), except that n is always provided, and you don't need to handle complex numbers.
If `n` is 1, then the array should be filled with the value min.

Needless to say, you should be careful not to modify memory off the ends of the array.

## 2. find_min
Write the function:

    int * find_min(int *array, int n)

which returns a pointer to the least element of the array (whose length is n).  If the array has no elements (n is 0), then the function should return NULL.


## 3. Increasing sequence
Return a pointer to the beginning of the longest sequence of continuously increasing integers in an array.  For example, given the array:

    int arr[] = { 7, 2, 10, 13, 15, 8, 3, 20 }

the fuction should return a pointer to `arr[1]`, since this begins the sequence {2, 10, 13, 15}.
If there are no sequences of increasing integers, then you should return NULL.  The integers do not need to increase by any particular amount; just that each number is strictly greater than the one before it.


