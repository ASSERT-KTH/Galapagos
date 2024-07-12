#!/bin/bash
set -x

while :
do
    python generate_variants_rq3.py

    LIB=$1

    python split_variants_miscompilation.py c $LIB
    python template_variants_miscompilation.py c $LIB
    python compile_variants_miscompilation.py c $LIB

    python -m tests.miscompilation bug-1 c

    N=`grep -r "\"correct transformations\": 1" out/bug-1 | wc -l`

    if [ $N != "0" ]; then
        exit 0
    fi
done
