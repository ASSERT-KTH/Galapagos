Below given is a semantically equivalent Go implementation of the provided C code. Due to Go's lack of pointer arithmetic, it won't be possible to directly translate all lines and due to its garbage collection systems, it's not needed to manually handle most deallocating operations like it is done in C. 

For the C functions that Go doesn't have equivalent for or does inherently as part of memory management like the _free_aligned() method for freeing memory, and _mprotect_readwrite() for changing protection on virtual memory pages we have omitted those in Go implementation. For the _out_of_bounds() exception type call in C, similar panic methods has been used in Go might not be exact line to line translation.

go

import (
    "crypto/subtle"
    "unsafe"
)

const CanarySize = 0 // Replace with actual canary size
var Canary = make([]byte, CanarySize) // Replace with actual canary

func SodiumFree(ptr unsafe.Pointer) {
    if ptr == nil {
        return
    }

    canaryPtr := ptr

    canary := *(*[]byte)(dlers.Payload(canaryPtr))

    result := subtle.ConstantTimeCompare(canary, Canary)

    if result != 1 {
        panic("Boundary check failed")
    }

    uintptrPtr:= uintptr(ptr)

    unprotectedPtr := (*unsafe.Pointer)(unsafe.Pointer(&uintptrPtr))
    basePtr := unprotectedPtr
    unprotectedSize := uint64(*(*uintptr)(unsafe.Pointer(&uintptrPtr)))

    totalSize := page_size + page_size + unprotectedSize + page_size;

    // Similar behavior using Slice (Go built-in data type)
    sliceHeader := (*reflect.SliceHeader)(unsafe.Pointer(&uintptrPtr));
    sliceHeader.Cap = size; 
    sliceHeader.Data = uintptrPtr;    
    sliceHeader.Len = zero;

    // As Go doesn't require explicit freeing of memory. This functionality is given to Garbage collector. 
    // Below line makes the garbage collector to think of arranging collection of memory which is allocated against underlying object.  
    // As root pointers holding the memory are set to zero.
    unsafe.Pointer(uintptrPtr) = nil
}
 
Few points to Note: In Go, since the absence of a proper equivalent to mprotect to control access to virtual memory pages, so the mprotect portion of the C code is not represented here, as direct pointer arithmetic is not allowed in Go.
Functions like mlock are typically not necessary or used in Go as Go provides safe memory management and garbage collection. 

Kindly note that the semaphore or other similar forceful memory management used in C may not necessary in GO due to managed memory in Go, so semaphore or equivalent operation have been left out here.