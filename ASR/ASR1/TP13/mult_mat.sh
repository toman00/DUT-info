#!/bin/bash

if [[ $1 -lt 0 ]]; then
	echo "Usage : $0 <arg1> <arg2>"
fi

if [[ $1 -lt 0 || $2 -lt 0 ]]; then
	echo "Arguments must be positive"
fi

if [[ $1 -gt $2 ]]; then
	echo " Warning : <arg1> must be lower than <arg2>"
fi

for (( j = $1; j <= $2; j++ )); do
	for (( i = $1; i <= $2; i++ )); do
		echo -n $(($i*$j))
		echo -ne "\t"

	done
	echo
done

exit

