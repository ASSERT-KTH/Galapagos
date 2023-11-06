#!/bin/bash

# set -x

# check cli args = 1
if [ $# -ne 1 ]; then
    echo "Usage: $0 project"
    exit 1
fi

# project is first arg
PROJECT=$1

LIB_DIR=$(pwd)/../use_cases/$PROJECT
FUNC_DIR=$(pwd)/../functions/$PROJECT

OUT="$FUNC_DIR/function_data.dat"

find $LIB_DIR -name *\.[ch] | xargs ctags -I STACK_OF+ --exclude=*test/* --exclude=*doc/* --fields='-{pattern}{kind}{typeref}{file}+{line}{end}' --output-format=json --kinds-c=f > $FUNC_DIR/function_definitions.dat

cd $LIB_DIR
find $LIB_DIR -type f -name *\.[ch] > cscope.files
cscope -R -b -q

while read a; do
    FUN=`echo $a | awk '{print substr($4, 2, length($4) - 3)}'`
    N=`cscope -d -L3 $FUN  | wc -l`
    echo "$a" | sed -E 's/[}]$/, \"count\": '"$N"'}/g'
done < $FUNC_DIR/function_definitions.dat > $OUT