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

