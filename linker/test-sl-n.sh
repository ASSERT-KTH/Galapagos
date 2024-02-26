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
$LLVM/clang -c -emit-llvm sum/sum.c -o main.c.bc
$LLVM/clang -c -emit-llvm sum/sum-variant.c -o main-variant.c.bc

$LLVM/llvm-dis main.c.bc -o main.c.ll
$LLVM/llvm-dis main-variant.c.bc -o main-variant.c.ll

$BIN main.c.bc main-variant.c.bc main-variant.c.bc --debug-level=1 --output=result.ll --function_name_in_input="sum" --function_name_in_replacement="sum" --sln --debug-level=2

$LLVM/llvm-as result.ll -o result.bc

$LLVM/clang result.bc -o result
echo "Executing variant "

./result

echo "Executing original "
$LLVM/clang sum/sum.c -o result.og
./result.og


# no alive verification on n-version
# echo "Calling alive to verify"
# $ALIVE result.bc main.c.bc --smt-to=3600000 --src-fn "sum" --tgt-fn "sum" -tgt-unroll=2 -src-unroll=2 --smt-max-mem=8192
# $ALIVE result.bc main.c.bc --smt-to=3600000 --src-fn "sum" --tgt-fn "sum" --smt-max-mem=8192

# cd ../
