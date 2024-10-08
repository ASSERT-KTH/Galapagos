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
    find $SHADOW_LOCATION -name '*\.[ch]' | xargs ctags -I STACK_OF+ --exclude=*test*/* --exclude=*doc*/* --exclude=*template.c --fields='-{pattern}{kind}{typeref}{file}+{line}{end}' --output-format=json --kinds-c=f > temp.dat
    echo "Finished ctags - 1st run"
    # Now, copy all the .i files to .c files, effectively replacing the original source files (useful for ctags)

    # IF it's libgcrypt, it's a bit different: .i files are put in /path/to/module/.libs/, instead of /path/to/module/
    # in that case, we must first remove all .c files from /path/to/module/ and then copy the .i files from /path/to/module/.libs/ to /path/to/module/, under a .c extension
    # it's important to remove them, because in libgcrypt's case, it seems like not all .c files have a matching .i file in .libs/, but rather, some are merged into a single .i file
    # for that:
    # - first, we find each module with .libs/*.i files under it
    # - then, we remove all .c files from the module
    # - finally, we copy the .i files from .libs/ to the module, under a .c extension

    if [ "$PROJECT" == "libgcrypt" ]; then
        # find all modules with .libs/*.i files -- beware that the module's path should not include .libs
        find $SHADOW_LOCATION -name '*\.i' | grep "\.libs" | xargs -I {} dirname {} | sort | uniq | while read module; do
            # remove the .libs/ from the module
            module=$(echo $module | sed 's/\/\.libs//')
            # remove all .c files from the module
            find $module -name '*\.c' -exec rm {} \;
            # copy the .i files from .libs/ to the module, under a .c extension
            cp $module/.libs/*.i $module/ && rename 's/\.i$/.c/' $module/*.i
        done
    else
        # copy the .i files to .c files
        find $SHADOW_LOCATION -name '*\.i' -exec sh -c 'for f; do cp "$f" "${f%.i}.c"; done' sh {} +
    fi

    echo "Finished renaming"
    find $SHADOW_LOCATION -name '*\.[ch]' | xargs ctags -I STACK_OF+ --exclude=*test*/* --exclude=*doc*/* --exclude=*template.c --fields='-{pattern}{kind}{typeref}{file}+{line}{end}' --output-format=json --kinds-c=f > temp2.dat
    echo "Finished ctags - 2nd run"
    # Now, comparing the two files and keeping only the functions that are in common
    # Each file has objects with various fields: the relevant ones are "path" and "name"; we want to keep the ones where both are the same
    # if the project is libgcrypt, we're forced to ignore the path, since the .c files are in a different location than the .i files
    if [ "$PROJECT" == "libgcrypt" ]; then
        python3 compare_ctags.py temp.dat temp2.dat $FUNC_DIR/function_definitions.dat --ignore-path
    else
        python3 compare_ctags.py temp.dat temp2.dat $FUNC_DIR/function_definitions.dat
    fi
    # below: creating a cscope database for the project
    # the database indexes the source code files, allows for efficient symbol lookup
    rm temp.dat temp2.dat
    echo "Finished comparing"
    cd $SHADOW_LOCATION
    find $SHADOW_LOCATION -type f -name '*\.[ch]' > cscope.files
elif [ "$FLAG" == "--source" ] || [ -z "$FLAG" ]; then
    find $LIB_DIR -name '*\.[ch]' | xargs ctags -I STACK_OF+ --exclude=*test*/* --exclude=*doc*/* --exclude=*template.c --fields='-{pattern}{kind}{typeref}{file}+{line}{end}' --output-format=json --kinds-c=f > $FUNC_DIR/function_definitions.dat
    # below: creating a cscope database for the project
    # the database indexes the source code files, allows for efficient symbol lookup
    cd $LIB_DIR
    find $LIB_DIR -type f -name '*\.[ch]' > cscope.files
else
    echo "Usage: $0 project [--source | --preprocessed] [shadow_location]"
    exit 1
fi

if [ "$FLAG" == "--preprocessed" ]; then
    echo $SHADOW_LOCATION
else
    echo $LIB_DIR
fi

