#!/bin/bash

echo "Hello, $name"

# printf "Hello, my favorite number is %d\n" 100

# Special parameters.
# $1 refers to the first command-line argument passed to this
# shell script when executed
echo $0
echo $1

echo
echo

echo $#

echo $@

if [[ "$name" == "Alex Guyer" ]]
then
	echo "Alright! It's you!"
fi

if [[ -f "some_file.txt" ]]
then

fi
