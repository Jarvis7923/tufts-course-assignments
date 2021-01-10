#! /bin/bash

# Put whatever tests you want here, e.g., 
# echo "words, words, words" | ./wordcount

# stdin test no option
echo -e "\nstdin test, no option"  
echo "> ./wordcount"
echo "words, words, words" | ./wordcount
echo ">  wc"
echo "words, words, words" | wc

# stdin test no option
echo -e "\nstdin test, two lines, no option"  
echo "> ./wordcount"
echo -e "words, words, \nwords" | ./wordcount
echo ">  wc"
echo -e "words, words, \nwords" | wc

# stdin test seperate option
echo -e "\nstdin test, -l"  
echo "> ./wordcount"
echo "words, words, words" | ./wordcount -l
echo ">  wc"
echo "words, words, words" | wc -l

echo -e "\nstdin test, -w"  
echo "> ./wordcount"
echo "words, words, words" | ./wordcount -w
echo ">  wc"
echo "words, words, words" | wc -w

echo -e "\nstdin test, -c"  
echo "> ./wordcount"
echo "words, words, words" | ./wordcount -c
echo ">  wc"
echo "words, words, words" | wc -c

# combine commands
echo -e "\nstdin test, -l -c"  
echo "> ./wordcount"
echo "words, words, words" | ./wordcount -l -c
echo ">  wc"
echo "words, words, words" | wc -l -c

echo -e "\nstdin test, -lw"  
echo "> ./wordcount"
echo "words, words, words" | ./wordcount -lw
echo ">  wc"
echo "words, words, words" | wc -lw


# file test 
echo -e "\nfile test, no option"  
echo "> ./wordcount"
./wordcount ../README.md
echo ">  wc"
wc ../README.md

# file test single option 
echo -e "\nfile test, -l"  
echo "> ./wordcount"
./wordcount -l ../README.md
echo ">  wc"
wc -l ../README.md

# file test, multiple options 
echo -e "\nfile test, -wl"  
echo "> ./wordcount"
./wordcount -wl ../README.md
echo ">  wc"
wc -wl ../README.md

echo -e "\nfile test, -w -c"  
echo "> ./wordcount"
./wordcount -w -c ../README.md
echo ">  wc"
wc -w -c ../README.md

# file name misplace
echo -e "\nerror test, file name misplace"  
echo "> ./wordcount ../README.md -l"
./wordcount ../README.md -l
echo ">  wc ../README.md -l"
wc ../README.md -l

# wrong option
echo -e "\nerror test, wrong option"  
echo "> ./wordcount -k ../README.md"
./wordcount -k ../README.md
echo ">  wc -k  ../README.md"
wc -k ../README.md

# no such file
echo -e "\nerror test, no such file"  
echo "> ./wordcount Jack.md"
./wordcount Jack.md 
echo ">  wc Jack.md"
wc Jack.md

