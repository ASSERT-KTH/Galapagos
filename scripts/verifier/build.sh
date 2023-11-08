echo "Building LLVM"
cd llvm
mkdir -p build
cd build
cmake -GNinja -DLLVM_ENABLE_RTTI=ON -DLLVM_ENABLE_EH=ON -DBUILD_SHARED_LIBS=ON -DCMAKE_BUILD_TYPE=Release -DLLVM_ENABLE_RTTI=ON  -DLLVM_TARGETS_TO_BUILD=X86 -DLLVM_ENABLE_ASSERTIONS=ON -DLLVM_ENABLE_PROJECTS="llvm;clang" ../llvm
cd ../../

echo "Building alive"
cd alive


mkdir -p build
cd build
echo $PWD
cmake -GNinja -DCMAKE_PREFIX_PATH=../../llvm/build  -DBUILD_TV=1 -DCMAKE_BUILD_TYPE=Release ..
ninja
