#!/usr/bin/env bash

# set -x

# check cli args >= 1
if [ $# -lt 1 ]; then
    echo "Usage: $0 project [--source | --preprocessed] [shadow_location]"
    exit 1
fi

# project is the first argument
PROJECT=$1
# then, a flag may be passed on whether the user wants information regarding source code files (.c, .h) or pre-processed files (.i)
# --source is default, --preprocessed is optional
FLAG=$2

LIB_DIR=$(pwd)/../use_cases/$PROJECT
FUNC_DIR=$(pwd)/../functions/$PROJECT

OUT="$FUNC_DIR/function_data.dat"

# FOUND_FILES will depend on FLAG -- [ch] if --source, i if --preprocessed
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
if [ "$FLAG" == "--preprocessed" ]; then
    SHADOW_LOCATION=$3
    echo "Shadow location: $SHADOW_LOCATION"
    find $SHADOW_LOCATION -name *\.[ch] | xargs ctags -I STACK_OF+ --exclude=*test*/* --exclude=*doc*/* --exclude=*template.c --fields='-{pattern}{kind}{typeref}{file}+{line}{end}' --output-format=json --kinds-c=f > temp.dat
    echo "Finished ctags - 1st run"
    # Now, copy all the .i files to .c files, effectively replacing the original source files (useful for ctags)
    find $SHADOW_LOCATION -name *\.i -exec sh -c 'for f; do cp "$f" "${f%.i}.c"; done' sh {} +
    echo "Finished renaming"
    find $SHADOW_LOCATION -name *\.[ch] | xargs ctags -I STACK_OF+ --exclude=*test*/* --exclude=*doc*/* --exclude=*template.c --fields='-{pattern}{kind}{typeref}{file}+{line}{end}' --output-format=json --kinds-c=f > temp2.dat
    echo "Finished ctags - 2nd run"
    # Now, comparing the two files and keeping only the functions that are in common
    # Each file has objects with various fields: the relevant ones are "path" and "name"; we want to keep the ones where both are the same
    python3 compare_ctags.py temp.dat temp2.dat $FUNC_DIR/function_definitions.dat
    # below: creating a cscope database for the project
    # the database indexes the source code files, allows for efficient symbol lookup
    rm temp.dat temp2.dat
    echo "Finished comparing"
    cd $SHADOW_LOCATION
    cscope -R -b -q
elif [ "$FLAG" == "--source" ] || [ -z "$FLAG" ]; then
    find $LIB_DIR -name *\.[ch] | xargs ctags -I STACK_OF+ --exclude=*test*/* --exclude=*doc*/* --exclude=*template.c --fields='-{pattern}{kind}{typeref}{file}+{line}{end}' --output-format=json --kinds-c=f > $FUNC_DIR/function_definitions.dat
    # below: creating a cscope database for the project
    # the database indexes the source code files, allows for efficient symbol lookup
    cd $LIB_DIR
    cscope -R -b -q
else
    echo "Usage: $0 project [--source | --preprocessed] [shadow_location]"
    exit 1
fi

# for each function definition, find the number of times it is called using the cscope database
while read a; do
    FUN=`echo $a | awk '{print substr($4, 2, length($4) - 3)}'`
    N=`cscope -d -L3 $FUN  | wc -l`
    echo "$a" | sed -E 's/[}]$/, \"count\": '"$N"'}/g'
done < $FUNC_DIR/function_definitions.dat > $OUT
