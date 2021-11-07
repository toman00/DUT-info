#!/bin/bash

if [[ $# -lt 2 ]]
then
    echo "Usage: $0 <SRC_FILE> <DEST_FILE>"
    exit
fi

if [[ ! -f $1 ]] 
then
    echo "file $1 does not exist !"
    exit
fi

if [[ -f $2 ]]
then
    echo -n "exists. Overwrite? Yes/No -->"
    read answer

    if [[ $answer == "Yes" ]]
    then
        rm $2
    fi
fi



for i in $(cat $1)
do
    x=$(expr substr $i 1 8)
    y=$(expr substr $i 9 8)
    z=$(expr substr $i 17 8)
    t=$(expr substr $i 25 8)

    echo "$((2#$x)).$((2#$y)).$((2#$z)).$((2#$t))" >> $2
done


exit