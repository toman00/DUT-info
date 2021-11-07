#!/bin/bash

#!/bin/bash

taille=3

echo -n "  X  |"
for ((abscisse=0;$abscisse<=$taille;abscisse++))
    do
        echo -n "  $abscisse  "
    done

echo
echo -n "-----+"
for((abscisse=0; $abscisse<=$taille;abscisse++))
    do
        echo -n "-----"
    done
echo
for ((ordonnee=0;$ordonnee<=$taille;ordonnee++))
    do
    echo -n "$ordonnee    |"
    for ((abscisse=0;$abscisse<=$taille;abscisse++))
        do
            echo -n "  $(($ordonnee*$abscisse))  "
        done
        echo
    done