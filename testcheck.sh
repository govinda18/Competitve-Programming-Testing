#!/bin/bash
if [ "$#" -ne 1 ];
then
	printf "Usage: ./test.sh <Number of test cases>\n"
	exit 1
fi

printf "Number of testcases = $1\n" 
if g++ -o generator generator.cpp;
then
	printf "\nGenerator compiled successfully.\n"
else
	printf "\nGenerator compilation failed.\n"
	exit 1
fi

cmd="./generator $1"
if timeout 30s $cmd;
then
	printf "\nGenerator executed successfully.\n"
else
	printf "\nGenerator execution failed due to timeout or runtime errors.\n"
	exit 1
fi

rm generator

if g++ -o solution solution.cpp;
then
	printf "\nOptimal solution compiled successfully.\n"
else
	printf "\nOptimal solution compilation failed.\n"
	exit 1
fi

if g++ -o checker checker.cpp;
then
	printf "\nChecker compiled successfully.\n"
else
	printf "\nChecker compilation failed.\n"
	exit 1
fi

for (( tno=1; tno<=$1; tno++ ))
do
	cat $tno > input.txt
	if timeout 30s ./solution<input.txt>sol.txt;
	then
		printf ""
	else
		printf "\nOptimal solution execution failed due to timeout or runtime errors.\n"
		exit 1
	fi
	
	if timeout 30s ./checker;
	then
		printf ""
	else
		printf "\nChecker execution failed due to timeout or runtime errors.\n"
		exit 1
	fi
done

rm solution
rm checker