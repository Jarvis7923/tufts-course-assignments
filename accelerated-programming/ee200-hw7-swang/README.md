# Resources
You should fill in this section with the resources that you used to develop your code.  You don't need to include the teaching staff or the textbook, but you should list anyone you worked with, and any online or paper resources you used.


# Overview
Unlike the previous problems, each of these is a complete program.  This has several implications:

1. These problems are significantly more complex than previous ones, and will require more careful planning.  If you write your algorithm in pseudocode or outline it in a comment, I would be happy to look over it and give you feedback before you start writing actual code.

2. You will test your program with a shell script and files you create, rather than as a series of calls to your function.  A shell script is just an automated way to run a sequence of commands, as if you were running them from the command line.

3. You will need to write Makefiles to compile your code.  The autograder script should be able to run `make all` in the problem directory (e.g., `activity`) to compile your code.

# Submission
Your code should be pushed to Github, and then you should submit to Gradescope from there.  You will not be able to upload files directly.

# Problems
## 1. Activity log
Write a program that logs activity to the file `activity.tsv`.  For example,

    ./log run 34 "getting back into shape"
    ./log bike 25 "grocery trip"
    ./log swim 40 "I'm doing a triathlon backwards"

The log file should consist of four columns in the following order, separated by tabs:
  1. Epoch time (seconds since 00:00 January 1, 1970 UTC)
  2. The activity, which could be any string ("run", "bike", etc) 
  3. The duration (in minutes)
  4. Notes

If the file does not exist, it should be created.  Otherwise, each call to `log` should keep the current contents of the log, and add a single line with the new activity.

Three of the columns are specified on the command line; the time should simply be the current time.  The note may be left empty.  However, if the activity or duration are not specified, the program should print a message containing the word 'usage', explaining to the user how the program should be used.

Your Makefile should produce a binary named `log`.

## 2. Activity summary
Write a program that summarizes activity over some duration of the past.  It should take a single argument, which is how far back from the current time to summarize.  For the above `log` commands,

    ./summarize 1w

should print:

    Total exercise: 99 minutes

The argument consists of an integer plus one of 'd', 'w', or 'y', for days, weeks or years respectively.

If the summary duration is not specifed, your program should print a message containing the word 'usage', explaining how the program should be used.
If the file does not exist or is corrupted, your program should print a message containing the word 'error'.

Your Makefile should produce a binary named `summarize`.

## 3. Word counting
Write an implementation of the Linux utility `wc`, which counts words, newlines, and bytes in a file.
It should take the name of a file on the command line, plus up to three optional arguments:

    -l  Print the number of newlines
    -w  Print the nubmer of words
    -c  Print the number of bytes (characters, including whitespace)

If no counts are specified, print all three.  The counts should always be printed in the order "newline, word, bytes", followed by the name of the file.  For example,

    $> wc README.md
    68 614 3618 README.md

    $> wc -c -l README.md
    68 3618 README.md

If no file is specified, you should read from stdin.
The optional arguments may be specified in any order; the file name is always last.

Your Makefile should produce a binary named `wordcount`.

