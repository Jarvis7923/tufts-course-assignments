#! /bin/bash

# This is a shell script which you can use to test your code
# To provide input, you can pipe text to standard input, which will be read by scanf

# `echo` just prints out whatever its command-line arguments are, and
# the `|` pipes the output of one command to the input of another.

echo "10+5" | ./problem1

# You can check the results with the following scripting magic:
result=echo "1 + 2" | ./problem1

readonly answer="3.000000"
if [ $result != $answer ]
  then echo "Test failed, expected $answer but got $result."
else
  echo "Test passed"
fi

# Add more test cases as necessary


