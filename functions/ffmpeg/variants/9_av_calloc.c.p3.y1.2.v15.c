In Go, memory allocation is handled by the built-in `make()`, both allocation and initialization are handle by `make()`. There is no equivalent of `size_mult(nmemb, size, &result)` in Go.

go
import "C"

func avCaloc(nmemb C.size_t, size C.size_t) unsafe.Pointer {
    result := C.size_t(C.ulonglong(nmemb) * C.ulonglong(size)) 

    mem, err := C.calloc(result, 1)
    if err != nil {
        return nil
    }

    return unsafe.Pointer(mem)
}

This assumes that the there is an equivalent of `av_mallocz()` encapsulated in `C.calloc()`. On a different node, Go doesn't need you to manually allocate and deallocate memory unlike C. So in real situation, you might not be using these approach.