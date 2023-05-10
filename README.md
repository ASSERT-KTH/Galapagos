# llm-envy

## Requirements

### Verifier module
- Uses alive2 with the translation validation tool. Steps for building here, https://github.com/AliveToolkit/alive2
    - Requirements for alive2 are needed: cmake, gcc/clang, re2c, Z3

### For running tests

- Build alive. `cd scripts/verification && bash build.sh`
- Enter the scripts folder
- Install it as a package `pip3 install -e .`
- Run each test module inside the `tests` folder. For example `pyrhon3 -m tests.openssl_usecase`


## Use cases

Include a use case by adding it as a submodule: `git submodule add <repo> use_cases/<name>`.

- `openssl`: Compile with `export CC=clang; export CXX=clang++; export CFLAGS="--save-temps"; export CXXFLAGS="--save-temps"; ./Configure; make`
