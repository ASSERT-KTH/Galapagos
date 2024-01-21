#!/usr/bin/env bash

# set -x

# check cli args = 1
if [ $# -ne 1 ]; then
    echo "Usage: $0 project"
    exit 1
fi

# project is the first (and only) argument
PROJECT=$1

LIB_DIR=$(pwd)/../use_cases/$PROJECT
FUNC_DIR=$(pwd)/../functions/$PROJECT

OUT="$FUNC_DIR/function_data.dat"

# finding both .c and .h files in LIB_DIR, use ctags to find function definitions
# regarding the options:
# -I STACK_OF+ : ignore STACK_OF macros
# --exclude=*test/* : ignore test files
# --exclude=*doc/* : ignore doc files
# --fields='...' : the fields to include in the tag file:
    # {pattern} : the search pattern, name of the function
    # {kind} : the kind of tag, e.g. function
    # {typeref} : the type of the tag
    # {file} : the file the tag is in
    # {line} : the line number at which the tag is defined
    # {end} : the line number at which the tag ends
# --output-format=json : output in json format
# --kinds-c=f : only include function definitions
find $LIB_DIR -name *\.[ch] | xargs ctags -I STACK_OF+ --exclude=*test/* --exclude=*doc/* --fields='-{pattern}{kind}{typeref}{file}+{line}{end}' --output-format=json --kinds-c=f > $FUNC_DIR/function_definitions.dat
# TODO: somehow make {file} relative to LIB_DIR, not absolute

# below: creating a cscope database for the project
# the database indexes the source code files, allows for efficient symbol lookup
cd $LIB_DIR
find $LIB_DIR -type f -name *\.[ch] > cscope.files
cscope -R -b -q

# for each function definition, find the number of times it is called using the cscope database
while read a; do
    FUN=`echo $a | awk '{print substr($4, 2, length($4) - 3)}'`
    N=`cscope -d -L3 $FUN  | wc -l`
    echo "$a" | sed -E 's/[}]$/, \"count\": '"$N"'}/g'
done < $FUNC_DIR/function_definitions.dat > $OUT