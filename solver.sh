#!/bin/bash
# Run from task directory (usually via a gen.sh script)
# Usage example: bash ../generate.sh

if [ "$#" -lt 1 ] || [ ! -e $1 ]; then
  echo "no solution file provided $#"
  exit 1
fi

sol=$1
run_solution=./solution
if [[ $sol == *.cpp ]]; then
    (set -x; g++ -O2 -std=c++17 -o solution $sol)
elif [[ $sol == *.c ]]; then
    (set -x; gcc -O2 -lm -o solution $sol)
elif [[ $sol == *.py ]]; then
    (set -x; run_solution="python3 $sol")
else
    echo "unsupported file extension"
    exit 1
fi

for input in $(find data -name "*.in" | sort); do
    output=${input%in}out
    # HOW TO DO THIS WITH set -v ???
    # (set -v; commands ... ) DOES NOT WORK
    echo "$run_solution < $input > $output"
    $run_solution < $input > $output
done
rm -f solution
