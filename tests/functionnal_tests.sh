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

echo -ne ":: nm\t\tRunning 64bits executable test... "

./my_nm my_nm &>tests/test.log
MY_RET=$?
nm my_nm &>tests/testcomp.log
EXP_RET=$?

diff_test tests/test.log tests/testcomp.log $MY_RET $EXP_RET
rm tests/test.log tests/testcomp.log

echo -ne ":: nm\t\tRunning 2 64bits executable test... "

./my_nm my_nm my_objdump &>tests/test.log
MY_RET=$?
nm my_objdump &>tests/testcomp.log
EXP_RET=$?

diff_test tests/test.log tests/testcomp.log $MY_RET $EXP_RET
rm tests/test.log tests/testcomp.log


echo -ne ":: objdump\tRunning invalid file test... "

./my_objdump Makefile &>/dev/null
MY_RET=$?
objdump -s -f Makfile &>/dev/null
EXP_RET=$?

ret_test $EXP_RET $MY_RET

echo -ne ":: objdump\tRunning 64bits executable test... "

./my_objdump my_objdump &>tests/test.log
MY_RET=$?
objdump -s -f my_objdump &>tests/testcomp.log
EXP_RET=$?

diff_test tests/test.log tests/testcomp.log $MY_RET $EXP_RET
rm tests/test.log tests/testcomp.log

echo -ne ":: objdump\tRunning objdump/src/objdump.o test... "

./my_objdump objdump/src/objdump.o &>tests/test.log
MY_RET=$?
objdump -s -f objdump/src/objdump.o &>tests/testcomp.log
EXP_RET=$?

diff_test tests/test.log tests/testcomp.log $MY_RET $EXP_RET
rm tests/test.log tests/testcomp.log

echo -ne ":: objdump\tRunning 32bits .so test... "

./my_objdump /usr/lib32/libcrypt.so &>tests/test.log
MY_RET=$?
objdump -s -f /usr/lib32/libcrypt.so &>tests/testcomp.log
EXP_RET=$?

diff_test tests/test.log tests/testcomp.log $MY_RET $EXP_RET
rm tests/test.log tests/testcomp.log

# exit $RET
