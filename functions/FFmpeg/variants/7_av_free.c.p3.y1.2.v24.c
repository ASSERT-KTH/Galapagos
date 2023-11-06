Go does not provide a direct equivalent to aligned_malloc() or _aligned_free(), but it does automatically take care of memory alignment. So here is how you can represent the semantics of the C function in Go:

go
import "C"

func av_free(ptr unsafe.Pointer){
    C.free(ptr)
}


The above code uses the "C" pseudo-package, so before it can run, cgo must be invoked.Sometimes Go's GC interferes with C's malloc/free, I don't recommend mixing them if not necessary. The Go runtime tries to minimize the reliance on C to foster portability across systems and environments.

Note: Avoid using unsafe.Pointer or cgo unless you're interfacing with C code, as it may lead to crashes or memory leaks.