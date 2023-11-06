go
import "C"
import "unsafe"

func sodium_memzero(pnt unsafe.Pointer, len uintptr) {
    C.memset(pnt, 0, len)
}

Please note, it is difficult to perfectly translate because the usage of preprocessor macro definition in C, which is depended on compiling flags and environment. Also, Go safety paradigm usually don't encourage directly memory operations, using high level concepts directly such as slice and map should avoid bugs, are easier to debug and manage. TypeError would be raised during compilation if wrong type of arguments are given.