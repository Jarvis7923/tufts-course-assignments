#!/bin/bash

echo "create folders" 
e="empty"
f="folder"

mkdir -p $e $f/$e


touch $f/file

echo
echo "test1: ./mytree "
./mytree 

echo
echo  "test2: ./mytree .. "
./mytree ..

echo
echo  "clean ... "

rm -rf $e $f  

