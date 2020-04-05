#! /bin/bash
echo "gcc -c main.c"
gcc -c main.c -std=c11 -Wall
echo "gcc -c gamelib.c "
gcc -c gamelib.c -std=c11 -Wall
echo "gcc -o game main.o gamelib.o "
gcc -o game main.o gamelib.o -std=c11 -Wall -lncurses 
