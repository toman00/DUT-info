#!/bin/bash

if [[ $# -ne 2 ]]; then
	echo "Invalid form : 2 arguments needed : <integer> <precision>"
fi

pos=$(expr index ".")
l=$(expr length $1)

for (( i = 1; i < $2; i++ )); do
	pad=$()
done