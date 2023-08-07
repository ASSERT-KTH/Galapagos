bash build.sh || exit 1

cd tests
BIN="../build/linker"
LLVM="../deps/llvm-Release-build/bin"


# Generating the chi
$LLVM/clang -c -emit-llvm chi/chi.c -o main.c.bc
llvm-goc -c -S -emit-llvm chi/chi.go -o main.go.bc
../deps/llvm-Release-build/bin/opt -strip-debug main.go.bc -o main.go.nod.bc

$BIN main.c.bc main.go.nod.bc --debug-level=5 --output=result.bc --function_name_in_input="Chi" --function_name_in_replacement="main.Chi"

cd ../
