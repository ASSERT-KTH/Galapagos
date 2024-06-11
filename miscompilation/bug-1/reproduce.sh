#!/usr/bin/bash

CLANG=/usr/bin/clang-15
ALIVE=../../scripts/verifier/alive/build/alive-tv

$CLANG main.c -O2 -save-temps -fno-strict-aliasing -o main
$CLANG main-variant.c -O2 -save-temps -fno-strict-aliasing -o main-variant

echo "executing original"
./main

echo "executing variantt"
./main-variant

echo "verifying equivalence"
$ALIVE main.bc main-variant.bc --src-fn "foo" --tgt-fn="foo" -smt-to=999999

