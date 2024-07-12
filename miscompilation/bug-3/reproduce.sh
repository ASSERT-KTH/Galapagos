#!/usr/bin/bash

CLANG=/usr/bin/clang-18
ALIVE=../../scripts/verifier/alive/build/alive-tv

$CLANG main.c -O3 -march=znver4 -flto=full -save-temps -fno-strict-aliasing -o main
$CLANG main-variant.c -O3 -march=znver4 -flto=full -save-temps -fno-strict-aliasing -o main-variant

echo "executing original"
./main
echo $?

echo "executing variantt"
./main-variant
echo $?

# echo "verifying equivalence"
$ALIVE main.bc main-variant.bc --src-unroll=2 --tgt-unroll=2  --src-fn "do_table" --tgt-fn="do_table" -smt-to=999999

