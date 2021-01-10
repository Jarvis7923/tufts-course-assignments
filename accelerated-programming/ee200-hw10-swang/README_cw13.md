# Resources
You should fill in this section with the resources that you used to develop your code.  You don't need to include the teaching staff or the textbook, but you should list anyone you worked with, and any online or paper resources you used.

# Overview
Exception safety is a simple concept but can be tricky in practice.  Don't hesitate to ask for help if you're stuck!

# Submission
Your code should be pushed to your classwork 10 repository, and then you should submit to Gradescope from there.  You will not be able to upload files directly.

# Problem

## Use exceptions
Upgrade your `Array` class to use C++ exceptions.  In particular, you should throw an `OutOfBoundsException` if the user tries to access an element that's off the end of the array.

Your `OutOfBoundsException` should inherit `std::exception` and implement the `what()` method, returning a string with at least the words "out of bounds", so it can be caught generically and printed.  In particular, the following code should catch the exception and print it:

    Array arr(3, 0);
    try {
      std::cout << "The fourth number is: " << arr[3] << std::endl;
    }
    catch (const std::exception& e){
      std::cout << "There was an error: " << e.what() << std::endl;
    }

## Exception safety
Your code should provide a "strong exception guarantee": if something happens which causes an exception, there should be no side effects.  That is, the object should be unmodified from its original state, and no memory should be leaked.  This will require thinking carefully about where exceptions could occur, and rewriting some functions to make them more robust.

The most likely cause for exceptions is allocating memory.  The autograder will cause `new` to fail while running your code, and will check that the exception is caught and your objects are not corrupted.  You can use the test code in `array/test_array_newfail.cpp` to cause `new` to throw an exception.

