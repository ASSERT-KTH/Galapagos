#!/usr/bin/bash

CLANG=/usr/local/bin/clang
ALIVE=../../scripts/verifier/alive/build/alive-tv

$CLANG main.c -Os -save-temps -fno-strict-aliasing -o main
$CLANG main-variant.c -Os -save-temps -fno-strict-aliasing -o main-variant

echo "executing original"
./main

echo "executing variantt"
./main-variant

echo "verifying equivalence"
$ALIVE main.bc main-variant.bc --src-fn "foo" --tgt-fn="foo" -smt-to=999999

