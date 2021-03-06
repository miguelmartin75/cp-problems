#!/bin/bash

BASE_DIR=sources

function count()
{
    find $1 -name "*.cpp" -or -name "*.java" -type f | wc -l
}

function print_table()
{
    dirs=(anzac atcoder codeforces codejam csacademy euler facebook geeksforgeeks hackerrank topcoder uva uwa codechef)

    echo "| SITE.| AMOUNT SOLVED"
    echo "|-----------.|---------------"
    total=0
    for d in ${dirs[@]}
    do
        c=$(count $BASE_DIR/$d)
        echo "| $d.| $c"
        total=$((total+$c))
    done

    echo "|-----------.|---------------"
    echo "| TOTAL.| $total"
}

print_table | column -t -s '.'
