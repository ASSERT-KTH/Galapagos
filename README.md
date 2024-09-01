# Galápagos: Automated N-Version Programming with LLMs

See paper "[Galápagos: Automated N-Version Programming with LLMs](http://arxiv.org/pdf/2408.09536)" (Javier Ron, Diogo Gaspar, Javier Cabrera-Arteaga, Benoit Baudry and Martin Monperrus), Technical report 2408.09536, arXiv, 2024."

```bibtex
@techreport{galapagos2024,
 title = {Galápagos: Automated N-Version Programming with LLMs},
 year = {2024},
 author = {Javier Ron and Diogo Gaspar and Javier Cabrera-Arteaga and Benoit Baudry and Martin Monperrus},
 url = {http://arxiv.org/pdf/2408.09536},
 number = {2408.09536},
 institution = {arXiv},
}
```

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

### Issues with use cases

#### Function types on extraction

Sometimes, due to the original source formatting and the way ctags works, the tags
don't always include the lines where the type of the function is declared. This
was fixed manually in some cases (namely, the ones below), which were:

- all the functions in liboqs, except `4_int16_nonzero_mask`
- all the functions in libsodium

#### libgcrypt's inline issue

For some reason, when compiling this project with the `Dinline` flag, the automatic
build pipeline we set up breaks; therefore, we had to manually remove the `inline`
keyword from the functions in libgcrypt.

### Running tests for each use case

#### ffmpeg

```sh
./configure
make && make check
```

#### libsodium

```sh
./autogen.sh -s
./configure
make && make check
```

#### openssl

```sh
./Configure
make test
```


#### alsa-lib

```sh
./gitcompile
# TODO: I'm not sure but `make check` doesn't seem to be everything??
make check # or cd test/ && make check-am && make check
```

#### liboqs
Requires. cmake version 3.25
```sh
sudo apt-get install -y astyle cmake gcc ninja-build libssl-dev unzip xsltproc doxygen graphviz valgrind
pip3 install pytest pytest-xdist pyyaml
mkdir build && cd build
cmake -DCMAKE_C_COMPILER="clang" -DCMAKE_C_FLAGS="--save-temps=obj -fno-strict-aliasing"  -DOQS_USE_OPENSSL=ON -DBUILD_SHARED_LIBS=ON -DCMAKE_INSTALL_PREFIX=/usr -DOPENSSL_ROOT_DIR=/usr/lib/x86_64-linux-gnu ..
make
make run_tests
```

#### libgcrypt

Checked out to ref `005292cf9f41179247918711b2968dd188aae122` because of Ubuntu's lack of availability of some package
versions - LIBGPG-error.

```sh
./autogen.sh -s
./configure --enable-maintainer-mode && make
make check
```
