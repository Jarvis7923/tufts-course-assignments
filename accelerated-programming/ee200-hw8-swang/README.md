# Resources
You should fill in this section with the resources that you used to develop your code.  You don't need to include the teaching staff or the textbook, but you should list anyone you worked with, and any online or paper resources you used.

# Overview
Like classwork 7, this is a complete program.  You will need to write your own Makefile, and test it with a shell script.  A good way to do testing would be for your shell script to actually create the directory structure using `mkdir` and `touch` (which creates an empty file), and then to run your program.

# Submission
Your code should be pushed to Github, and then you should submit to Gradescope from there.  You will not be able to upload files directly.

# Problem
Write an implementation of the Linux utility `tree`, which prints out the subdirectory structure of the directory specified on the command line.  If no directory is specified, use the current working directory.

    $> mytree homework_08
    homework_08
        README.md
        tree
            problem1.c

Note that in Unix/Linux, every directory contains a `.` and `..` directory which refer to the current directory and the directory above.  Don't include these in your printout; that doesn't add any information and leads to infinite loops.
You should also ignore hidden files and directories (which begin with a `.`), such as `.git`.

You should indent each successive directory level by 4 spaces.
You do not need to print the pretty lines or color labels (although these are nice features of `tree`), nor the summary line at the bottom (e.g., "1 directory, 2 files").

Some functions that will be helpful (use `man` to read about them):
* `opendir`
* `readdir`
* `closedir` (It's important to clean up after yourself, even if your code works without doing so.)
* `snprintf`

Your Makefile should produce a binary called `mytree`.

This is a common problem, and there are implementations online if you search for them.  Remember that 1) all code you write must be your own, and 2) you need to document any sources you used to develop your solution.

