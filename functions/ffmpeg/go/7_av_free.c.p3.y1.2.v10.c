In Go, there is no need for specific alignment handling in case of memory deallocation. You simply have to call selected Free functions of the specific use cases. Further handling can be seen while allocating.

Go:

go
import (
    "unsafe"
    "runtime"
)

func av_free(ptr unsafe.Pointer) {
    runtime.KeepAlive(ptr)
}


The `runtime.KeepAlive` function is used in situations where you have an unsafe reference to an object (for example, if it was allocated outside of the Go runtime by C code as in the given function). The runtime.KeepAlive call says "Hey, I still care about this data / object, don't clean up until at least this point in the code."

However, note that Go does not allow you to manually manage memory by default. If you come from a manual memory management language such as C or C++, you might expect manual control but Go doesn’t let you do that. Go prefers garbage-collected memory management, where runtime automatically handles cleaning up of unreachable open memory segments.

If you are trying to free up the blocks you got from calling C.malloc using unsafe.Pointer or calling some other C API, the correct solution would be to call C.free in that context. Here's how you would implement C-like free function in Go using cgo bridging and the fact that uintptr can store unsafe.Pointer values by defining C's malloc and free via //export:

go
/*
#include <stdlib.h>
#include <stdint.h>

uint8_t *c_malloc(size_t n) {
    return malloc(n);
}

void c_free(void *p) {
    free(p);
}
*/
import "C"
import "unsafe"

func av_free(ptr unsafe.Pointer) {
    C.c_free(ptr)
}

This can be invoked like:

go
//Allocate using CGo C malloc.
str := C.c_malloc(128)

...

// Deallocate when you're done with it.
av_free(unsafe.Pointer(str))


It’s also important to flag that using "C" package the indirect runtime/cgo, might not perform as well on platforms like Windows because of thread-local storage, potentially.

In real-world Go programs it's preferable to use the built-in mechanisms for allocation/deallocation rather than trying to replicate those from C or another manually-managed memory language. Usually, it's also better design as Go mechanisms are robustly built, tested and used.