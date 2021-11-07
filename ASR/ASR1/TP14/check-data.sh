#!/bin/bash


if [[ $# -ne 3 ]]; then
	echo "Invalid form : 3 arguments needed : <STRINGS_REPRESENTATIONS_FILE><radix> <REPORTS_FILE>"
	exit
fi

if [[ $2 -lt 2 || $2 -gt 36 ]]; then
	echo "The radix must be a decimal between 2 and 36"
	exit
fi

if [[ ! -f $1 ]]; then
	echo "$1 file doesn't exist !"
	exit
fi

if [[ -f $3 ]]; then
	echo -n "$3 exists : Override ? Yes/No -->"
	read answer
	echo
	if [[ $answer == "Yes" ]]; then
		rm $3
	else 
		exit
	fi
fi


DIGITS=0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ

LEGAL_DIGITS=$(expr substr $DIGITS 1 $2)


while read line
do
	res="" # résultat intermédiaire, stockage des digits non-voulus
	l=$(expr length $line) # nombre de caractère sur la ligne line
	for (( i = 1; i <= $l; i++ )); do
		digit=$(expr substr $line $i 1)
		pos=$(expr index $LEGAL_DIGITS $digit)
		if [[ $pos -eq 0 ]]; then
			res=$res$digit
		fi
	done
	echo "$line : $res"
done < $1 >$3
	exit