#!/bin/sh

filename=$1
outFile="${filename%.*}"
g++ $1 -fsanitize=address -std=c++11 -o $outFile -O2 -Wall -Wextra
