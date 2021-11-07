#!/bin/bash

echo "Entrez un entier : "
read x

for ((i=0;i<=x;i++))
    do
        echo "$x x $i = $(($x*$i))"
    done
