#!/bin/bash
# Run from task directory
# Usage example: bash gen/gen.sh

# Wrong solution ideas
# - split by 'of' then remove all leading 'the's
# - remove all 'the's then split by 'of'
# - split by 'of' then reverse all
# - lowercase all then something 
# - split by 'of' without first splitting by ' '
#   - a regular word may have an 'of' substring
        
# Test case ideas
# sub1 - n <= 1000 and no 'the'
# - one character
# - one regular word
# - only regular words
# - one of
# - some of
# - nearly all of
# - all of
# - a regular word has 'of' as a substring (handcase)
# - a regular word has 'the' as a substring (handcase)
#
# sub2 - n <= 1000 with 'the' and 'of'
# - only the
# - only the and of (handcase)
# - only the and one of (handcase)
# - regular words and the
# - regular words, of and one the 
# - regular words, of and many the
# - regular words, of and normal the 
#
# REMOVED sub3 - n <= 100'000 with 'the' and 'of'
# - all of, no the
# - all of, high the
# - normal density of regular words, of and the 

mkdir -p data/secret
rm data/secret/*

echo "Generating inputs"
g++ -std=c++17 -O2 -o random gen/random.cpp

# SUB1 - n <= 1000 and no 'the'
# - one character
./random 1 1 0 0 > data/secret/sub1-01.in

# - one regular word
./random 5 1 0 0 > data/secret/sub1-02.in

# - only regular words
./random 1000 100 0 0 > data/secret/sub1-03.in

# - one of
./random 1000 100 0 1 > data/secret/sub1-04.in

# - some of
./random 1000 100 0 20 > data/secret/sub1-05.in

# - nearly all of
./random 1000 100 0 98 > data/secret/sub1-06.in

# - all of
./random 1000 100 0 99 > data/secret/sub1-07.in

# - a regular word has 'of' as a substring (handcase)
# > handcase/sub1-01.in 

# - a regular word has 'the' as a substring (handcase)
# > handcase/sub1-02.in 
# > handcase/sub1-03.in

# SUB2 - n <= 1000 with 'the' and 'of'
# only the
./random 1000 0 100 0 > data/secret/sub2-01.in

# - regular words and the
./random 1000 100 100 0 > data/secret/sub2-02.in

# - regular words, of and one the 
./random 1000 100 1 20 > data/secret/sub2-03.in

# - regular words, of and many the
./random 1000 50 200 20  > data/secret/sub2-04.in

# - regular words, of and normal the 
./random 1000 100 20 20 > data/secret/sub2-05.in

# - only the and of (handcase)
# > handcase/sub2-01.in

# - only the and one of (handcase)
# > handcase/sub2-02.in

# # SUB3 - n <= 100'000 with 'the' and 'of'
# # - all of, no the
# ./random 100000 10000 0 9999 > data/secret/sub3-01.in

# # - all of, high the
# ./random 100000 5000 8000 4999 > data/secret/sub3-02.in

# # - regular words, of and the 
# ./random 100000 10000 1000 1000 > data/secret/sub3-03.in

rm random

echo "Generating outputs"
bash ../gen-output.sh solutions/accepted/clayton.py

