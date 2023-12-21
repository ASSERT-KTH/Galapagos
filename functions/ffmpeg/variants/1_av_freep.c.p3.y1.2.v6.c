Notably, there's a fundamental problem with porting C code that makes careful use of pointers directly into Go. In Go, taking the address of a dereferenced pointer or copying pointer addresses, like we do here with memcpy, is generally not done, and might not be possible, as pointer arithmetic is not one of the concepts of Go. However, in this case `arg` expected at supposed to pointer to pointer.

In Go, it would be a matter different due to the garbage collection nature, hence, after removing the `arg` link we don't need to worry about cleanup.

Here is a possible similar version in Go.

go
import "unsafe"

func av_freep(arg *unsafe.Pointer) {
    *arg = nil
}

It's important to note that `unsafe` package is generally discouraged to use and not considered to be safe machine memory operations.