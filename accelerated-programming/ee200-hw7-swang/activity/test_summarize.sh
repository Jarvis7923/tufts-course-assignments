#!/bin/bash

# Put whatever tests you want here, e.g., 
# ./summarize 3d

FILE=activity.tsv
echo "Content in $FILE"
cat activity.tsv

echo -e "\nCheck 1d"
./summarize 1d

echo "Remove file $FILE."

if test -f "$FILE"; then
    echo "$FILE exists. Removing old files"
    rm $FILE
fi

echo "Create file $FILE."
touch $FILE

cur=$(date +'%s')
test_1y=$((cur+10-365*24*60*60*1))

test_1w=$((cur+10-7*24*60*60*1))

test_1d=$((cur+10-24*60*60*1))

echo -e "$test_1y\trun\t10\tsummarize 1y" >> $FILE

echo -e "$test_1w\trun\t10\tsummarize 1w" >> $FILE

echo -e "$test_1d\trun\t10\tsummarize 1d" >> $FILE


echo "Content in $FILE"
cat activity.tsv

echo -e "\nCheck 1d"
res=$(./summarize 1d)
if [[ $res == *"Total exercise: 10 minutes"* ]]; then
    echo "Corrct ... Test passed "
else 
    echo "Incorrect answer"
fi
echo -e "\nCheck 1w"
res=$(./summarize 1w)
if [[ $res == *"Total exercise: 20 minutes"* ]]; then
    echo "Corrct ... Test passed "
else 
    echo "Incorrect answer"
fi
echo -e "\nCheck 1y"
res=$(./summarize 1y)
if [[ $res == *"Total exercise: 30 minutes"* ]]; then
    echo "Corrct ... Test passed "
else 
    echo "Incorrect answer"
fi

# wrong arg
echo -e "\nInvalid arg test, 22"
res=$(./summarize 22)
if [[ $res == *"usage"* ]]; then
    echo "Usage printed ... Test passed "
else 
    echo "Test fails, no keywords "usage" found "
fi

# wrong arg
echo -e "\nInvalid arg test, yy"
res=$(./summarize yy)
if [[ $res == *"usage"* ]]; then
    echo "Usage printed ... Test passed "
else 
    echo "Test fails, no keywords "usage" found "
fi
# wrong arg
res=$(./summarize )
if [[ $res == *"usage"* ]]; then
    echo "Usage printed ... Test passed "
else 
    echo "Test fails, no keywords "usage" found "
fi

echo -e "\nDelete the file..."
rm $FILE
echo -e "\nEmpty file test"
res=$(./summarize 1y)
if [[ $res == *"error"* ]]; then
    echo "Error printed ... Test passed "
else 
    echo "Test fails, no keywords "error" found "
fi










