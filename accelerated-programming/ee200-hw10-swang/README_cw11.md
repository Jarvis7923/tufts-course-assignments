# Resources
You should fill in this section with the resources that you used to develop your code.  You don't need to include the teaching staff or the textbook, but you should list anyone you worked with, and any online or paper resources you used.

# Overview
In this assignment, you'll upgrade your `Array` class to use proper constructors and a destructor.  Again, be sure to use Valgrind at some point in your testing, since OOP features in C++ make it very easy to leak memory.

Like Classwork 10, you don't need to submit a Makefile, but we suggest writing one to make your life easier.

Also like previous assignments, you'll need to write you own test code.  To the extent possible, you should test each function individually, rather than in one monolithic test.  This ensures that errors in one function don't get masked by errors in other functions.

# Submission
Your code should be pushed to your Classwork 10 Github repository, and then you should submit to Gradescope from there.  You will not be able to upload files directly.

# Problem
Upgrade your `Array` class to include:

* A default constructor, which takes no arguments
* Constructor which takes the length and an initial value for all elements: `Array(int length, int value)`
* Constructor which takes the length and a pointer to an array to initialize the elements: `Array(int length, int* values)`.  You may assume that if the pointer is not NULL, it points to a valid array that holds at least `length` elements.  The Array should create its own copy of the data.
* Copy constructor, which creates a deep copy of the Array.
* Destructor which cleans up any memory associated with the Array
* You should be able to write the array to a stream using the `<<` operator.  The result should be a comma-separated list of values enclosed in square brackets, like `[1, 3, 5, 7]`.
* An overload of the `+` operator which concatenates two arrays.  You should be able to chain concatenation operations, such as `z = a + b + c`

These functions should be public; all implementation details of your class should be private.

You should remove your `initialize()` and `cleanup()` functions, in favor of the constructors and destructor.

You may continue using `malloc` and `free` to manage memory, or you can switch to `new` and `delete`.

