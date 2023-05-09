#!/bin/bash

LIB_DIR=$HOME/openssl
OUT="function_data.dat"

find $LIB_DIR -name *\.[ch] | xargs ctags -I STACK_OF+ --exclude=*test/* --exclude=*doc/* --fields='-{pattern}{kind}{typeref}{file}+{line}{end}' --output-format=json --c-types=f > function_definitions.dat

while read a; do
    FUN=`echo $a | awk '{print substr($4, 2, length($4) - 3)}'`
    N=`grep -horE --include \*.c --include \*.h.* "[ *]$FUN\(" "$LIB_DIR" | wc -l`
    echo "$a" | sed -E 's/[}]$/, \"count\": '"$N"'}/g'
done < function_definitions.dat > $OUT