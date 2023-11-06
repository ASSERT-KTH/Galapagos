Here is the equivalent Go code, assuming that `sodiumMalloc` serves the role of `_sodium_malloc`:

Note: Go has an excellent `Garbage Collector` that automatically frees memory so the analog of malloc is often unnecessary, but to stick as close to the original function semantics, we can use `make()` to create a byte slice, and then convert that to a normal pointer.

Go
import (
    "C"
    "unsafe"
)

const GARBAGE_VALUE = (some_integer_value_that_replicates_original_implementation) 

func sodiumMalloc(size C.size_t) unsafe.Pointer {

    ptr := C.sodiumMalloc(size)
    
    if ptr == nil {
        return nil
    }
    
    data := (*[1 << 30]byte)(ptr)
    for i := 0; i < int(size); i++ {
        data[i] = GARBAGE_VALUE
    }
    
    return ptr
}


KINDLY NOTE that putting values into this memory would be highly dangerous, as violating this could destroy the runtime or crash the process. Therefore, it is extremely perilous to continue using this returned pointer on your own inside Go -- please avoid unless it is extremely necessary (generally there's not a reason to handle allocation oneself in Go).

This Go function above replicates the usefulness and "unsafe" behavior replicating the original C code understands. Appropriately memory management (allocation & deallocation) is simpler under normal Go `Garbage Collector`. If best practice linto wanted, then returning []byte "byte slice" is the possibly & appropriate semantic equivalent.