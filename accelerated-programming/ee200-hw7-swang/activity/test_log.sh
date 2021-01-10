#! /bin/bash

# Put whatever tests you want here, e.g., 
# ./log run 80 "long run today"

# expample inputs

FILE=activity.tsv
if test -f "$FILE"; then
        echo "$FILE exists. Removing old files"
        rm $FILE
    fi

echo -e "\nCheck regular"
./log run 34 "getting back into shape"

echo "Content in $FILE"
cat activity.tsv

# empty note
echo -e "\nCheck empty note"
./log war 300
echo "Content in $FILE"
cat activity.tsv

# Insufficient argumnent test
echo -e "\nInsuffcient arguments"
res=$(./log hike)

if [[ $res == *"usage"* ]]; then
    echo "Usage printed ... Test pass "
else 
    echo "Test fails, no keywords "usage"found "
fi


# Invalid duration test
echo -e "\nInvalid duration"
res=$(./log hike hello "get a pair of shoes")

if [[ $res == *"usage"* ]]; then
    echo "Usage printed ... Test pass "
else 
    echo "Test fails, no keywords "usage"found "
fi






