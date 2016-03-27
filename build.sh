#!/bin/sh
g++ *.cpp -o numerus-test -std=c++0x
if [ $? = 0 ]; then
	echo "Done building."
fi
