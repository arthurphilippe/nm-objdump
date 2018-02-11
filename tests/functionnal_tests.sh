#!/bin/bash

RET=0

function diff_test {
	diff $1 $2 -q &> /dev/null
	if [ $? -ne 0 ]; then
		echo "NOK"
		RET=1
		diff $1 $2 --color=auto
		echo "***"
		echo
	else
		if [ $3 -ne $4 ]; then
			echo "KO"
			echo "Expected return status $3 but got status $4"
		else
			echo "OK"
		fi
	fi
}

function ret_test {
	if [ $1 -ne $2 ]; then
		echo "KO"
		echo "Expected return status $1 but got status $2"
	else
		echo "OK"
	fi
}

echo -ne ":: nm\t\tRunning invalid file test... "

./my_nm Makefile &>/dev/null
MY_RET=$?
nm Makfile &>/dev/null
EXP_RET=$?

ret_test $EXP_RET $MY_RET

echo -ne ":: objdump\tRunning invalid file test... "

./my_objdump Makefile &>/dev/null
MY_RET=$?
objdump -s -f Makfile &>/dev/null
EXP_RET=$?

ret_test $EXP_RET $MY_RET
