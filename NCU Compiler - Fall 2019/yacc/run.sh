#!/bin/bash

bison -d -o y.tab.c $1.y
gcc -c -g -I.. y.tab.c
flex -o lex.yy.c $1.l
gcc -c -g -I.. lex.yy.c
gcc -o $1 y.tab.o lex.yy.o -ll -lm

./$1 < input_$1.txt > output_$1.txt

