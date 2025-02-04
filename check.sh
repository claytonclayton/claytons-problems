#!/bin/bash/

# Run from task directory after running bash ../gen-output.sh
# Usage example: bash ../check.sh

# Description: Tests all solutions in solutions/accepted against
# expected output. Green for AC, red for WA, yellow for TLE. 

time_limit=1

i=1
col_sep=0
in_names=()
sol_names=()
ex=()

for sol in solutions/accepted/*; do
    run_solution=./solution

    if [[ $sol == *.cpp ]]; then
        g++ -O2 -std=c++17 $sol -o $i
        ex+=(./$i)
    elif [[ $sol == *.c ]]; then
        gcc -O2 -lm $sol -o $i
        ex+=(./$i)
    elif [[ $sol == *.py ]]; then
        ex+=("python3 $sol")
    else
        echo "unsupported file extension"
        continue
    fi

    short=${sol#solutions/accepted/}
    short=${short%.*}
    sol_names+=($short)
    ((i++))
done

check() {
    x=$1
    sol_name=$2
    file=$3
    expected=$4

    actual=$(timeout $time_limit $x < $file)
    exit_code=$?
    if [ $exit_code -ne 0 ]; then
        printf "\033[1;93m$sol_name\033[0m " # 1;33 for original darker yellow
    elif diff -wq $expected <(echo $actual) > /dev/null; then
        printf "\033[1;32m$sol_name\033[0m " 
    else
        printf "\033[1;31m$sol_name\033[0m "
    fi
}

for file in $(find data -name "*.in" | sort); do
    in_name=${file#"data/"}
    in_name=${in_name%.in}
    in_names+=$in_name
    sep=$(echo $in_name | wc -c)
    if [ $sep -gt $col_sep ]; then
        col_sep=$sep
    fi
done

for file in $(find data -name "*.in" | sort); do
    expected=${file%in}out
    in_name=${file#"data/"}
    in_name=${in_name%.in}
    sep=$(echo $in_name | wc -c)
    
    echo -n $in_name ""

    for i in ${!sol_names[@]}; do
        check "${ex[$i]}" "${sol_names[$i]}" $file $expected
    done
    echo ""
done

for i in "${ex[@]}"; do
    if [[ $i =~ ^\./ ]]; then
        rm ${i#./}
    fi
done
