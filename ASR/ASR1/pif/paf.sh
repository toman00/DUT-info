#!/bin/bash


x=$((RANDOM%11))

echo $x
echo -n "X |"


for ((i=0; $i<=x;i++))
	do
		echo -n " $i "
	done
echo
for ((i=0;$i<=$x;i++))
	do
		echo -n "$i |"
		for ((j=0;$j<=$x;j++))
			do
				echo -n " $((i*j)) "
			done
		echo
	done

exit
