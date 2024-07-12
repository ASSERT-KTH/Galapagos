#!/bin/bash

LIB=$1

for LANG in "c" "go"; do
    python split_variants.py $LANG $LIB
    python template_variants.py $LANG $LIB
    python compile_variants.py $LANG $LIB
done
