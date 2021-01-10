# Resources
You should fill in this section with the resources that you used to develop your code.  You don't need to include the teaching staff or the textbook, but you should list anyone you worked with, and any online or paper resources you used.


# Overview
In this and future classwork sets, you will write a set of functions or programs which perform some operation or compute a particular result.

Each problem is in its own directory, with the following files (where <N> is the number of the problem):
  problem<N>.c        The starter code for the functions you must write
  test_problem<N>.c   An example test file which calls the function(s)

To compile these, you should run
  gcc problem<N>.c test_problem_<N>.c -o problem<N>

And then run the result with:
  ./problem<N>
  
You are welcome to add anything to either file, but you should not modify the existing function declarations.  That is, write your code in the functions, and add more functions as necessary, but don't change the names of the existing functions or their parameters.  Doing so may cause our grading scripts to fail.

# Testing and grading
You should expect that we will give "bad" inputs to your code, and it should handle them gracefully.  
For example, if the input to a function is a positive integer, you should expect that we will test it with a negative integer.
If the behavior is not specified for some input, then your code can do anything, as long as it doesn't crash.

# Submission
You should commit and push your code to GitHub when you reach any significant milestone (you finish a problem, or get a function tested and working).
When you are finished, submit your code on Gradescope via Github.

# Problems
## 1.
Write a function that prints the prime factors of an integer.  The prime factors are the set of prime numbers that when multiplied together produce the original number.  Some factors may be repeated.  For example, the factors of 20 would be `2 2 5`.

The input to the function is an int; it should return 0 if it was successful; -1 if it was not (e.g., the number doesn't have any prime factors).  The prime factors should be separated by whitespace (spaces, tabs, or newlines); do not print anything else.  Remember that 1 is not prime.

## 2.
Write a function that returns the largest integer power of 2 that is less than or equal to N (i.e., 5 returns 4, 12 returns 8, etc.).  Return 0 if there is no such power.

# 3.
Write a function that behaves like a simple calculator: it takes two double-precision arguments and a character operand (one of '+', '-', '*', '/', or '^') and returns the result as a double.
You might want to use the `pow` function; type `man pow` at the command-line for the reference page. (If you use 'pow', you'll need to add -lm to your gcc command.)

If the operation is invalid, print a message containing the word "error" and return 0.

# 4.
Write a function that returns the triangle with the larger area.  A `Triangle` is a `struct` of three `Point`s, each of which is a struct with `x` and `y` coordinates.

    typedef struct {
      double x;
      double y;
    } Point;
    
    typedef struct {
      Point a;
      Point b;
      Point c;
    } Triangle;
    
    Triangle getLarger(Triangle first, Triangle second);

If the triangles have equal area, return the first one.

# 5.
Write a function that prints out N random integers in the range [0, MAX), i.e., inclusive of 0 but not MAX.
The numbers should be separated by whitespace.

You will probably want to use the `rand()` function.  Type `man 3 rand` at a command prompt for the reference page.

