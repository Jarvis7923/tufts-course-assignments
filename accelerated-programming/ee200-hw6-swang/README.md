# Resources
You should fill in this section with the resources that you used to develop your code.  You don't need to include the teaching staff or the textbook, but you should list anyone you worked with, and any online or paper resources you used.


# Overview
These problems are similar to previous ones --- you will write a function that returns a particular result, and an external test function will call it with various inputs.

# Submission
Your code should be pushed to Github, and then you should submit to Gradescope from there.  You will not be able to upload files directly.

# Problems
## 1. Tic-Tac-Toe
Write a function which checks a tic-tac-toe board for a win condition; i.e., one or the other players has completed a row of 3, either vertically, horizontally, or diagonally.  The board is a 3x3 array of char, which contains `x`, `o`, ` `, and possibly invalid characters.
Your function should return:

* `x` if X has won,
* `o` if O has won,
* ` ` (space) if the game is still going,
* `.` if the game if no one has won and all the spaces are filled ("cat's game")
* `\0` (NULL) if the board is invalid (contains invalid characters, or there are more 'x' or 'o' than would be possible if players were taking turns).

## 2. Convert to lowercase
Write a function which converts the characters in a string to lowercase:

    void lower(char* str);

Characters which are not letters should not be modified.  The function should not crash if given a NULL string.  You should not use any C string functions in your implementation.

## 3. Cipher cracking
The textbook motivated the need for arrays by discussing cipher cracking by counting characters, but never implemented this function.  Write a function which computes a histogram of characters a-z for a string of length `len`:

    void find_frequency(const char* str, int len, unsigned int histogram[26])

The result in `histogram` should be a count of the occurances of each character in the string: The number of 'a's in histogram[0], etc.
Uppercase and lowercase letters should be treated as the same character; other characters should be ignored.  You should avoid writing a 26-case switch statement in your code, which means you'll need to be clever with the ASCII representation and array indexing.

## 4. Short string finding
Given an array of strings, find the shortest one and return a pointer to it:

    const char* find_shortest(const char * const * strings, int len)

You can assume that the strings are well-formed; that is, any string which is not NULL is terminated properly with a `\0`.

