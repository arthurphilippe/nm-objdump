#!/bin/bash


##            Colors
ESC="\033["
C_RED=$ESC"0;31m"
C_BRED=$ESC"1;31m"
C_BGREEN=$ESC"1;32m"
C_RST=$ESC"0m"

RET=0

if [ -z "$1" ]; then
	VAL=$(echo my_nm)
else
	VAL=$1
fi

function color {
	echo -ne $2
	echo -n $1
	if [ -z "$3" ]; then
		echo -e $C_RST
	else
		echo -ne $C_RST
	fi
}

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
			color "KO" $C_BRED
			echo "Expected return status $3 but got status $4"
		else
			color "OK" $C_BGREEN
		fi
	fi
}

function ret_test {
	if [ $1 -ne $2 ]; then
		color "KO" $C_BRED
		echo "Expected return status $1 but got status $2"
	else
		color "OK" $C_BGREEN
	fi
}

function line_test {
	if [ $1 -ne $2 ]; then
		color "KO" $C_BRED 1
		echo " (got $2)"
		color "---- Expected ----" $C_BGREEN
		tmp=$(nm $VAL | grep " $4 ")
		printf "$tmp"
		echo
		color "----    Got   ----" $C_BRED
		tmp=$(./my_nm $VAL | grep " $4 ")
		printf "$tmp"
		echo
	else
		color "OK" $C_BGREEN 1
		echo " (got $2)"
	fi
}

echo -ne ":: objdump\tRunning invalid file test... "

./my_objdump Makefile &>/dev/null
MY_RET=$?
objdump -s -f Makfile &>/dev/null
EXP_RET=$?

ret_test $EXP_RET $MY_RET

echo -ne ":: objdump\tRunning 64bits executable test... "

./my_objdump my_objdump &>tests/test1.log
MY_RET=$?
objdump -s -f my_objdump &>tests/test1comp.log
EXP_RET=$?

diff_test tests/test1.log tests/test1comp.log $MY_RET $EXP_RET
rm tests/test1.log tests/test1comp.log

echo -ne ":: objdump\tRunning main.o test... "

./my_objdump nm/src/main.o &>tests/test2.log
MY_RET=$?
objdump -s -f nm/src/main.o &>tests/test2comp.log
EXP_RET=$?

diff_test tests/test2.log tests/test2comp.log $MY_RET $EXP_RET
rm tests/test2.log tests/test2comp.log

echo -ne ":: objdump\tRunning 32bits .so test... "

./my_objdump /usr/lib32/libcrypt.so &>tests/test3.log
MY_RET=$?
objdump -s -f /usr/lib32/libcrypt.so &>tests/test3comp.log
EXP_RET=$?

diff_test tests/test3.log tests/test3comp.log $MY_RET $EXP_RET
# rm tests/test2.log tests/test2comp.log

# exit $RET

echo
echo -e "\t\tnm: test on $VAL"
echo


echo -ne ":: nm\t\tRunning invalid file test... "

./my_nm Makefile &>/dev/null
MY_RET=$?
nm Makfile &>/dev/null
EXP_RET=$?

ret_test $EXP_RET $MY_RET

echo -ne ":: nm\t\tDiff Number Lines... "

MY_RET=$(./my_nm $VAL | wc -l)
EXP_RET=$(nm $VAL | wc -l)

line_test $EXP_RET $MY_RET $VAL

echo -ne ":: nm\t\tDiff Number Lines on 'A' flag... "

MY_RET=$(./my_nm $VAL | grep " A " | wc -l)
EXP_RET=$(nm $VAL | grep " A " | wc -l)

line_test $EXP_RET $MY_RET $VAL "A"

echo -ne ":: nm\t\tDiff Number Lines on 'B' flag... "

MY_RET=$(./my_nm $VAL | grep " B " | wc -l)
EXP_RET=$(nm $VAL | grep " B " | wc -l)

line_test $EXP_RET $MY_RET $VAL "B"

echo -ne ":: nm\t\tDiff Number Lines on 'b' flag... "

MY_RET=$(./my_nm $VAL | grep " b " | wc -l)
EXP_RET=$(nm $VAL | grep " b " | wc -l)

line_test $EXP_RET $MY_RET $VAL "b"

echo -ne ":: nm\t\tDiff Number Lines on 'C' flag... "

MY_RET=$(./my_nm $VAL | grep " C " | wc -l)
EXP_RET=$(nm $VAL | grep " C " | wc -l)

line_test $EXP_RET $MY_RET $VAL "C"

echo -ne ":: nm\t\tDiff Number Lines on 'D' flag... "

MY_RET=$(./my_nm $VAL | grep " D " | wc -l)
EXP_RET=$(nm $VAL | grep " D " | wc -l)

line_test $EXP_RET $MY_RET $VAL "D"

echo -ne ":: nm\t\tDiff Number Lines on 'd' flag... "

MY_RET=$(./my_nm $VAL | grep " d " | wc -l)
EXP_RET=$(nm $VAL | grep " d " | wc -l)

line_test $EXP_RET $MY_RET $VAL "d"

echo -ne ":: nm\t\tDiff Number Lines on 'G' flag... "

MY_RET=$(./my_nm $VAL | grep " G " | wc -l)
EXP_RET=$(nm $VAL | grep " G " | wc -l)

line_test $EXP_RET $MY_RET $VAL "G"

echo -ne ":: nm\t\tDiff Number Lines on 'g' flag... "

MY_RET=$(./my_nm $VAL | grep " g " | wc -l)
EXP_RET=$(nm $VAL | grep " g " | wc -l)

line_test $EXP_RET $MY_RET $VAL "g"

echo -ne ":: nm\t\tDiff Number Lines on 'i' flag... "

MY_RET=$(./my_nm $VAL | grep " i " | wc -l)
EXP_RET=$(nm $VAL | grep " i " | wc -l)

line_test $EXP_RET $MY_RET $VAL "i"

echo -ne ":: nm\t\tDiff Number Lines on 'I' flag... "

MY_RET=$(./my_nm $VAL | grep " I " | wc -l)
EXP_RET=$(nm $VAL | grep " I " | wc -l)

line_test $EXP_RET $MY_RET $VAL "I"

echo -ne ":: nm\t\tDiff Number Lines on 'N' flag... "

MY_RET=$(./my_nm $VAL | grep " N " | wc -l)
EXP_RET=$(nm $VAL | grep " N " | wc -l)

line_test $EXP_RET $MY_RET $VAL "N"

echo -ne ":: nm\t\tDiff Number Lines on 'p' flag... "

MY_RET=$(./my_nm $VAL | grep " p " | wc -l)
EXP_RET=$(nm $VAL | grep " p " | wc -l)

line_test $EXP_RET $MY_RET $VAL "p"

echo -ne ":: nm\t\tDiff Number Lines on 'R' flag... "

MY_RET=$(./my_nm $VAL | grep " R " | wc -l)
EXP_RET=$(nm $VAL | grep " R " | wc -l)

line_test $EXP_RET $MY_RET $VAL "R"

echo -ne ":: nm\t\tDiff Number Lines on 'r' flag... "

MY_RET=$(./my_nm $VAL | grep " r " | wc -l)
EXP_RET=$(nm $VAL | grep " r " | wc -l)

line_test $EXP_RET $MY_RET $VAL "r"

echo -ne ":: nm\t\tDiff Number Lines on 'S' flag... "

MY_RET=$(./my_nm $VAL | grep " S " | wc -l)
EXP_RET=$(nm $VAL | grep " S " | wc -l)

line_test $EXP_RET $MY_RET $VAL "S"

echo -ne ":: nm\t\tDiff Number Lines on 's' flag... "

MY_RET=$(./my_nm $VAL | grep " s " | wc -l)
EXP_RET=$(nm $VAL | grep " s " | wc -l)

line_test $EXP_RET $MY_RET $VAL "s"

echo -ne ":: nm\t\tDiff Number Lines on 'T' flag... "

MY_RET=$(./my_nm $VAL | grep " T " | wc -l)
EXP_RET=$(nm $VAL | grep " T " | wc -l)

line_test $EXP_RET $MY_RET $VAL "T"

echo -ne ":: nm\t\tDiff Number Lines on 't' flag... "

MY_RET=$(./my_nm $VAL | grep " t " | wc -l)
EXP_RET=$(nm $VAL | grep " t " | wc -l)

line_test $EXP_RET $MY_RET $VAL "t"

echo -ne ":: nm\t\tDiff Number Lines on 'U' flag... "

MY_RET=$(./my_nm $VAL | grep " U " | wc -l)
EXP_RET=$(nm $VAL | grep " U " | wc -l)

line_test $EXP_RET $MY_RET $VAL "U"

echo -ne ":: nm\t\tDiff Number Lines on 'u' flag... "

MY_RET=$(./my_nm $VAL | grep " u " | wc -l)
EXP_RET=$(nm $VAL | grep " u " | wc -l)

line_test $EXP_RET $MY_RET $VAL "u"

echo -ne ":: nm\t\tDiff Number Lines on 'v' flag... "

MY_RET=$(./my_nm $VAL | grep " v " | wc -l)
EXP_RET=$(nm $VAL | grep " v " | wc -l)

line_test $EXP_RET $MY_RET $VAL "v"

echo -ne ":: nm\t\tDiff Number Lines on 'V' flag... "

MY_RET=$(./my_nm $VAL | grep " V " | wc -l)
EXP_RET=$(nm $VAL | grep " V " | wc -l)

line_test $EXP_RET $MY_RET $VAL "V"

echo -ne ":: nm\t\tDiff Number Lines on 'w' flag... "

MY_RET=$(./my_nm $VAL | grep " w " | wc -l)
EXP_RET=$(nm $VAL | grep " w " | wc -l)

line_test $EXP_RET $MY_RET $VAL "w"

echo -ne ":: nm\t\tDiff Number Lines on 'W' flag... "

MY_RET=$(./my_nm $VAL | grep " W " | wc -l)
EXP_RET=$(nm $VAL | grep " W " | wc -l)

line_test $EXP_RET $MY_RET $VAL "W"

echo -ne ":: nm\t\tDiff Number Lines on '?' flag... "

MY_RET=$(./my_nm $VAL | grep " ? " | wc -l)
EXP_RET=$(nm my_nm | grep " ? " | wc -l)

line_test $EXP_RET $MY_RET $VAL "?"
