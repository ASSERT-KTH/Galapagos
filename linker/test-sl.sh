# bash build.sh || exit 1
cd tests
BIN="../build/linker"
LLVM="../deps/llvm-Release-build/bin"
LLVM_GO="../deps/llvm-Release-build-go/bin"
ALIVE="../../scripts/verifier/alive/build/alive-tv"


# Generating the chi
$LLVM/clang -c -emit-llvm chi/chi.c -o main.c.bc
$LLVM/clang -c -emit-llvm chi/chi-variant.c -o main-variant.c.bc

$LLVM/llvm-dis main.c.bc -o main.c.ll
$LLVM/llvm-dis main-variant.c.bc -o main-variant.c.ll

$BIN main.c.bc main-variant.c.bc --debug-level=1 --output=result.ll --function_name_in_input="Chi" --function_name_in_replacement="Chi" --lang=0 --debug-level=2

$LLVM/llvm-as result.ll -o result.bc

$LLVM/clang result.bc -o result
echo "Executing variant "

./result

echo "Executing original "
$LLVM/clang chi/chi.c -o result.o
./result.o 


# echo "Calling alive to verify"
# $ALIVE main.c.bc  result.bc --src-fn "Chi" --tgt-fn "Chi"

# cd ../
