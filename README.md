# llm-envy

## Requirements

### Verifier module
- Uses alive2 with the translation validation tool. Steps for building here, https://github.com/AliveToolkit/alive2
    - Requirements for alive2 are needed: cmake, gcc/clang, re2c, Z3

### For running tests

- Build alive. `cd scripts/verifier && bash build.sh`
- Enter the scripts folder
- Install it as a package `pip3 install -e .`
- Run each test module inside the `tests` folder. For example, `python3 -m tests.usecase ffmpeg`

## Use cases

Include a use case by adding it as a submodule: `git submodule add <repo> use_cases/<name>`.
Furthermore, each use case must have an entry on the `LIBRARY_INFO` dictionary
inside `scripts/usecase/case.py`, with all its dependencies, possible compilation flags
and environment variables, as well as some other settings such as whether testing
should be enabled.

### Running tests for each use case

#### coreutils

```sh
./bootstrap
./configure
# NOTE: some tests skipped because of the lack of root, others because of being deemed "too expensive" -- how much of a problem is this? from 480 in total, 87 are skipped
make && make check
```

#### ffmpeg

```sh
./configure
make && make check
```

#### libsodium

```sh
./autogen -s
./configure
make && make check
```

#### mako

```sh
./autogen -s
./configure
make && make check
```

#### openssl

```sh
./Configure
make test
```

