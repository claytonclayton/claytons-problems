#!/bin/bash
# Run from task directory
# Usage example: bash gen/gen.sh

mkdir -p data/secret

echo "Generating inputs"

echo -e "1" > data/secret/1.in
echo -e "17" > data/secret/2.in
echo -e "233" > data/secret/3.in
echo -e "625" > data/secret/4.in
echo -e "999" > data/secret/5.in

echo "Generating outputs"
bash ../gen-output.sh solutions/accepted/clayton.cpp

