## Functions linker

This tools takes two  LLVM bitcodes and links them together. It takes a function from the second bitcode and replace the function in the first bitcode by it.

This tool only works if the first bitcode comes from C and the second bitcode comes from Go.


## Building

- Run `bash build_deps.sh`
- Run `bash build.sh`

## Testing

- Run `bash test.sh`
