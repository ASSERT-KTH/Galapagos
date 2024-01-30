In Go, this could look something like the following:

go
import (
    "C"
    "unsafe"
    "reflect"
    "bytes"
)

const (
    PAGE_SIZE = uintptr(4096) // A default value (Can check system page size for an appropriate value instead)
)

func SodiumFree(ptr unsafe.Pointer) {
    var canary []byte
    var totalSize uintptr
    var unprotectedSize int
    var unprotectedPtr unsafe.Pointer

    if ptr == nil {
        return
    }
    
    canaryPtr := uintptr(ptr) - int(unsafe.Sizeof(canary))
    val := reflect.NewAt(reflect.TypeOf(unprotectedSize), unsafe.Pointer(uintptr(ptr) - PAGE_SIZE*2)).Elem()
    unprotectedSize = int(val.Int())
    unprotectedPtr = unsafe.Pointer(uintptr(ptr) - PAGE_SIZE*2)
    basePtr := unsafe.Pointer(uintptr(unprotectedPtr) - PAGE_SIZE *2)
    totalSize = PAGE_SIZE + PAGE_SIZE + uintptr(unprotectedSize) + PAGE_SIZE

    C.mprotect(basePtr, totalSize, C.PROT_READ|C.PROT_WRITE)

    if !bytes.Equal(C.GoBytes(canaryPtr, C.int(len(canary))), canary) {
        OutOfBounds()
    }
    
    // Only if the operating system does NOT have page protection  
    if !bytes.Equal(
      C.GoBytes(unsafe.Pointer(uintptr(unprotectedPtr) + uintptr(unprotectedSize)), C.int(len(canary))),
      canary) {
        OutOfBounds()
    }

    C.munlock(unprotectedPtr, C.size_t(unprotectedSize))
    FreeAligned(basePtr, totalSize)
}


Please replace `const PAGE_SIZE = 4096` with the code that gets your OS Page Size. Also replacing sodium_memcmp to bytes.Equal does the work of comparing byte slices here. `Munlock`, `mprotect` and `FreeAligned` are system dependent operations that aren't straight forward to migration. Some conversions were needed regarding uintptr manipulation. 

Warnings: 

This direct migration may need adjustments according to your codebase and use.

Direct system operations (`munlock`, `FreeAligned`, `mprotect`) has to modeled specifically as such concepts need to understand by system perspective in Go language (not straight forward wrapper provided that are safe enough), hence explicit function are not provided above, take this as pseudocode to compelete rest of your implementation. Needs protections for system security and you might want to put rest of the code under some expert review for using such dangerous operations directly with system and while using package `unsafe`. 

Conversions between C and Go types (pointer manipulation and types void and size_t) had limited guidance and tricky due to security measures taken by Go natively to avoid such unsafe operations, as this involves package `unsafe` and cgo which indeed needing specific and rigid error checking which needed to get tuned with requirements and for not introducing bugs relating unsafe unknown void type pointers; requires validation and treatment accordingly.
