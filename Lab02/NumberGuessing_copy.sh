#!/bin/sh

showRange() {
	echo -n "Please enter a number between $1 and $2: "
}

echo 'Welcome to the Number Guessing Game!'
min=0
max=10

while true
do
	showRange $min $max;
	read guess

	if [ $guess -gt $1 ]; then
		max=`expr $guess - 1`
	elif [ $guess -lt $1 ]; then
		min=`expr $guess + 1`
	else
		echo "Bingo!"
		break
	fi
done

