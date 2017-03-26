#!/bin/bash

function count()
{
    find $1 -name "*" -type f | wc -l
}

function print_table()
{
    dirs=(codeforces topcoder uva contests)

    echo "| SITE.| AMOUNT SOLVED"
    echo "|-----------.|---------------"
    total=0
    for d in ${dirs[@]}
    do
        c=$(count $d)
        echo "| $d.| $c"
        total=$((total+$c))
    done

    echo "|-----------.|---------------"
    echo "| TOTAL.| $total"
}

print_table | column -t -s '.'
