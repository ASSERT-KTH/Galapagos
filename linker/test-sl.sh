# bash build.sh || exit 1
#
#

set -x

cd tests
BIN="../build/linker"
LLVM="../deps/llvm-Release-build/bin"
LLVM_GO="../deps/llvm-Release-build-go/bin"
ALIVE="../../scripts/verifier/alive/build/alive-tv"


# Generating the chi
$LLVM/clang -c -emit-llvm zero/zero.c -o main.c.bc
$LLVM/clang -c -emit-llvm zero/zero-variant.c -o main-variant.c.bc

$LLVM/llvm-dis main.c.bc -o main.c.ll
$LLVM/llvm-dis main-variant.c.bc -o main-variant.c.ll

$BIN main.c.bc main-variant.c.bc --debug-level=1 --output=result.ll --function_name_in_input="sodium_is_zero" --function_name_in_replacement="sodium_is_zero" --sld --debug-level=2

$LLVM/llvm-as result.ll -o result.bc

$LLVM/clang result.bc -o result
echo "Executing variant "

./result

echo "Executing original "
$LLVM/clang sum/sum.c -o result.og
./result.og


echo "Calling alive to verify"
$ALIVE result.bc main.c.bc --smt-to=3600000 --src-fn "sodium_is_zero" --tgt-fn "sodium_is_zero" -tgt-unroll=5 -src-unroll=5 --smt-max-mem=8192
# $ALIVE result.bc main.c.bc --smt-to=3600000 --src-fn "sum" --tgt-fn "sum" --smt-max-mem=8192

# cd ../
