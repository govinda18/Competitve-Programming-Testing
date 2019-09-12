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

if g++ -o brute brute.cpp;
then
	printf "\nBrute force solution compiled successfully.\n"
else
	printf "\nBrute force solution compilation failed.\n"
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
	
	if timeout 30s ./brute<input.txt>brute.txt;
	then
		printf ""
	else
		printf "\nBrute force solution execution failed due to timeout or runtime errors.\n"
		exit 1
	fi
	DIFF=$(diff sol.txt brute.txt -b  --ignore-space-change -B  --ignore-blank-lines)
	if [ "$DIFF" != "" ];
	then
		printf "$tno - Wrong answer\n"
	else
		rm $tno
		printf "$tno - OK\n"
	fi
done

rm input.txt
rm brute.txt
rm sol.txt
rm solution
rm brute