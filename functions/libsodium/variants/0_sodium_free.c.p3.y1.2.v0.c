To replicate this function with semantical equivalence in Go would be exceedingly complex and impractical given that many necessary components (e.g., _unprotected_ptr_from_user_ptr, _mprotect_readwrite, _out_of_bounds and _free_aligned), if they do exist, are platform dependent. Thus, certain library functions used in C do not have direct translate to Go due to its memory management. 

Additionally, Go has its own garbage collector that frees the memory when it is not referenced anymore. Hence a delete-style function from C to free memory is not required in Go.

Therefore, the requested transformation of sodium_free is unrealistic without significant reinterpretation. The interface for managing such low-level buffer would fundamentally differ between Go and C (speaking theoretically).

Here is an function signature and skeleton (TEMPLATE & HYPOTHETICAL CODE - most components are NOT real in Go). This will give a rough idea and parallelism to original C function:

func SodiumFree(ptr unsafe.Pointer){
    var basePtr []byte
    var canaryPtr []byte 
    var unprotectedPtr []byte
    var totalSize uintptr 
    var unprotectedSize uintptr 

    if uintptr(ptr) == 0 {
        return
    }

    canaryPtr = base.GoSliceToBytes(C.GoBytes(ptr, C.sizeof_ulong))
    unprotectedPtr = _unprotectedPtrFromUserPtr(ptr)
    basePtr = unprotectedPtr - PageSize * 2 
    unprotectedSize = GoShallowSize(basePtr)
    totalSize = PageSize * 4 + unprotectedSize
    _a_protectReadWrite(basePtr, totalSize)
    
    parentCanary := C.GoSliceToBytes(shouldValFromRef(canary))
    
    defer func() {
        if reflect.DeepEqual(parentCanary, canaryPtr)
            _outOfBounds() // imagined a panic().
        }

      if NotImplementedPageProtection == true {
        defer func() {
          if reflect.DepthEqual(UnSecureCanary, canaryPtr) 
              _outOfBounds() //imagin a panic()
            }
    }
    
    sodium_munlock(unprotectedPtr, unprotectedSize)    //assuming the func is available in Go.
    _freeAligned(basePtr, total_size)                  //assuming the func is available in Go.
}

Again reiterated that use of functions such as "_unprotectedPtrFromUserPtr", "_outOfBounds()", "_freeAligned", "_a_protectReadWrite" are hypothetically placed for corresponding matching params and not actual component.

Please seek to writing dedicated modules in Go for sodium based works that look forward to C's memory management and low level processing approaches.
If these pointers deal so bit-wise / memory accessing works in go it is better to do it on fundamentals Go's ways. For instance using interfaces and struct associated functions.

Important sidenotes:
Functions in Go by defaults are given letter case based accessibility status. Given some function 'func processData()', it is private due uncapitilized defined which avoids access level issue as bear from normal safety design perspective.