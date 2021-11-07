#!/bin/bash

x=$((RANDOM%101))


echo "Entrez une valeur entre 0 et 100 : "
valeur=NULL
while [[ $valeur -ne $x ]]
	do
		read valeur
		if [[ $valeur -gt $x ]]; then
			echo "C'est moins !"
		fi

		if [[ $valeur -lt $x ]]; then
			echo "C'est plus !"
		fi

		if [[ $valeur -eq $x ]]; then
			echo "ENFIN !"
			break
		fi

		
	done
echo "La valeur était : $x"
