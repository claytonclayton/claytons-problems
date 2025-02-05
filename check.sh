#!/bin/bash/

# Run from task directory after running bash ../gen-output.sh
# Usage example: bash ../check.sh

# Description: Tests all solutions in solutions/accepted against
# expected output. Green for AC (Accepted), red for WA 
# (Wrong Answer), yellow for TLE (Time Limit Exceeded). 

time_limit=1

i=1
col_sep=0
in_names=()
in_files=()
sol_names=()
ex=()

repeat() {
    for i in $(seq $1); do
	echo -n "$2"
    done
}

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

for file in $(find data -name "*.in" | sort); do
    in_name=${file#"data/"}
    in_name=${in_name%.in}
    in_names+=($in_name)
    in_files+=($file)
    sep=$(echo $in_name | wc -c)
    if [ $sep -gt $col_sep ]; then
        col_sep=$sep
    fi
done

for i in ${!in_names[@]}; do
    in_name=${in_names[$i]}
    sep=$(echo $in_name | wc -c)
    replacer=$in_name"$(repeat $(($col_sep - $sep)) ' ' )"
    in_names[$i]=$replacer
done

for i in ${!in_files[@]}; do    
    in_name=${in_names[$i]}
    file=${in_files[$i]}
    expected=${file%in}out

    echo -n "$in_name" ""

    for j in ${!sol_names[@]}; do
        check ${ex[$j]} ${sol_names[$j]} $file $expected
    done
    echo ""

done

for i in "${ex[@]}"; do
    if [[ $i =~ ^\./ ]]; then
        rm ${i#./}
    fi
done
