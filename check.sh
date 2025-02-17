#!/bin/bash/

# Run from task directory after running bash ../gen-output.sh
# Usage example: bash ../check.sh
#                bash ../check.sh <file or folder name>
# Description: Tests all solutions in target file or folder 
# (or in solutions/accepted if not specified) against
# expected output. Green for AC (Accepted), red for WA 
# (Wrong Answer), yellow for TLE (Time Limit Exceeded). 

time_limit=1

i=1
col_sep=0
sol_dir='solutions/accepted'
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
    in_file=$3
    expected=$4

    actual=$(timeout $time_limit $x < $in_file)
    exit_code=$?
    if [ $exit_code -ne 0 ]; then
        printf "\033[1;93m$sol_name\033[0m " # 1;33 for original darker yellow
    elif diff -wq $expected <(echo $actual) > /dev/null; then
        printf "\033[1;32m$sol_name\033[0m " 
    else
        printf "\033[1;31m$sol_name\033[0m "
    fi
} 

if [ $# -ne 0 ] && [ -d $1 -o -f $1 ]; then
    sol_dir=$1
fi

for sol in $(find "$sol_dir" -type f); do
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
        continue
    fi

    short=$(basename $sol)
    short=${short%.*}
    sol_names+=($short)
    ((i++))
done

if [ ${#ex[@]} -eq 0 ]; then
    echo "error: could not find any solution files"
    exit 0
fi

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
    in_file=${in_files[$i]}
    expected=${in_file%in}out

    echo -n "$in_name" ""

    for j in ${!sol_names[@]}; do
        check "${ex[$j]}" ${sol_names[$j]} $in_file $expected
    done
    echo ""

done

for i in "${ex[@]}"; do
    if [[ $i =~ ^\./ ]]; then
        rm ${i#./}
    fi
done
