#!/bin/bash


echo "Entrez la taille du tableau :"
read x
echo


for ((i=0;i<$x;i++))
    do
        for ((j=0;j<$x;j++))
            do
                echo -ne "$i\t"
            done
        echo
    done