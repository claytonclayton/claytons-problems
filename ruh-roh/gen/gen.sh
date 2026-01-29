#!/bin/bash
# Run from task directory
# Usage example: bash gen/gen.sh

mkdir -p data/secret

# test ideas
# x - starts with one big number then all 1. Reaches all 1s in one jump.
# x - same as above but reaches all 1s in two jumps.
# 

g++ gen/generator.cpp -o generator
echo "Generating inputs"

# small and large numbers
./generator 100 4 0 > data/secret/01.in
./generator 100 4 1 > data/secret/02.in # should return -1
./generator 1000000 1000 0 > data/secret/03.in
./generator 1000000 1000 1 > data/secret/04.in # should return -1

# small numbers
./generator 100 40 2 > data/secret/05.in
./generator 1000000 400000 2 > data/secret/06.in

# medium numbers
./generator 100 10 3 > data/secret/07.in
./generator 1000000 5000 3 > data/secret/08.in

# all ones
./generator 1000000 1000000 4 > data/secret/09.in
./generator 1000000 999999 4 > data/secret/10.in # should return -1

# one jump
./generator 1000000 1 5 > data/secret/11.in

# two jumps
./generator 1000000 2 6 > data/secret/12.in
./generator 1000000 1 6 > data/secret/13.in # should return -1

rm generator

echo "Generating outputs"
bash ../gen-output.sh solutions/accepted/Ruh-roh-Noah.cpp


