#!/bin/bash

name_list=()
# notice: there should be a space after [ and before ].
# [] equals test
#if [ -s ./name_list.txt ]
if test -s ./name_list.txt
then
    name_list=$(cat name_list.txt)
    echo "file exist!"
else
    name_list=("Bob, Aglaia")
    echo file not exist!
fi

# If there is any space in the line, it will output as two names
for name in $name_list
do
    echo Hello, $name
done

count=0;
#while [ $count -lt 3 ]
for((i=0;i<3;++i))
do
    echo time count: $count.
    if [ 0 -eq $((count%2)) ]
    then
        echo $count is an even number
    fi
    sleep 1
    # here we use "(())" to calculate integers and use "$" to
    # get the result of the expression.
    count=$((count += 1))
done


