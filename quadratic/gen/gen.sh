#!/bin/bash
# Run from task directory
# Usage example: bash gen/gen.sh

mkdir -p data/secret

echo "Generating inputs"

# absolutely silly data
echo "0 0 0 0" > data/secret/1.in
echo "1 0 1 0" > data/secret/2.in
echo "0 -1 0 -1" > data/secret/3.in
echo "-1 -1 -1 -1" > data/secret/4.in
echo "1 1 1 1" > data/secret/5.in
echo "1 0 1 1" > data/secret/6.in
echo "0 1 -1 1" > data/secret/7.in
echo "2 0 -1 -2" > data/secret/8.in
echo "2 -2 0 -1" > data/secret/9.in
echo "10000 10000 10000 10000" > data/secret/10.in
echo "-10000 -10000 -10000 -10000" > data/secret/11.in
echo "10000 10000 10000 -10000" > data/secret/12.in
echo "2 -2 2 2" > data/secret/13.in

# more silliness
g++ gen/gen.cpp -o jenny
./jenny -100 100 > data/secret/14.in
./jenny -10000 10000 > data/secret/15.in

# thank you jenny
rm jenny

echo "Generating outputs"
bash ../gen-output.sh solutions/accepted/clayton.cpp 

