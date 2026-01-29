#!/bin/bash
# Run from task directory
# Usage example: bash gen/gen.sh

mkdir -p data/secret

g++ gen/generator.cpp -o genny

echo "Generating inputs"

./genny 100 0 > data/secret/1.in
./genny 100 1 > data/secret/2.in
./genny 100 50 > data/secret/3.in
./genny 100 100 > data/secret/4.in

./genny 1000000 0 > data/secret/5.in
./genny 1000000 1 > data/secret/6.in
./genny 1000000 100000 > data/secret/7.in
./genny 1000000 1000000 > data/secret/8.in

rm genny 

echo "Generating outputs"
bash ../gen-output.sh solutions/accepted/clayton.cpp


