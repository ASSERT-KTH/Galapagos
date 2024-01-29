In Go, the semantically equivalent could be as follows:

go
import (
    "os"
    "unsafe"
    "reflect"
    "syscall"
    "crypto/subtle"
)

func sodium_free(ptr unsafe.Pointer) {
    var canary []byte // Actual canary value should be set
    page_size := os.Getpagesize()

    if ptr == nil {
        return
    }

    canaryPtr := (*byte)(ptr) - uintptr(len(canary))
    unprotectedPtr := _unprotectedPtrFromUserPtr(ptr)
    basePtr := uintptr(unprotectedPtr) - uintptr(page_size*2)
    unprotected_size := *(*int)(unsafe.Pointer(basePtr))
    total_size := page_size + page_size + unprotected_size + page_size
    _mprotect_readwrite(basePtr, total_size)
    if subtle.ConstantTimeCompare((*[len(canary)]byte)(unsafe.Pointer(canaryPtr))[:], canary) != 0 {
        _out_of_bounds()
    }

    if subtle.ConstantTimeCompare(((*[len(canary)]byte)(unsafe.Pointer(uintptr(unprotectedPtr) + uintptr(unprotected_size))))[:], canary) != 0 {
        _out_of_bounds()
    }

    sodiumMunlock(unprotectedPtr, unprotected_size)
    _freeAligned(basePtr, total_size)
}


NOTES:
1. Functions like "_unprotectedPtrFromUserPtr", "_mprotect_readwrite", "_out_of_bounds", "sodiumMunlock", and "_freeAligned" are assumed to be available elsewhere in the Go code base. 
2. The actual value of the `canary` array needs to be set. 
3. Lack of preprocessor macros in Golang prevents from writing equivalent of `#ifndef HAVE_PAGE_PROTECTION`. However, configuration should be managed differently in Golang (e.g. via OS environment or through built options when compiling your code).
4. This translation keeps the basic structure and approach of the original code − performing a cryptographically secure constant-time compare, and freeing up memory space. The actual code may differ based on invisible dependencies.
