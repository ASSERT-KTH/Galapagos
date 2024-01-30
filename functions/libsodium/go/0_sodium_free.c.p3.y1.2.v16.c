Go does not operate in the same manner as C and does not manage memory in the same explicit way, which makes directly converting the function quite challenging and might even not be fully feasible. However, similar functionality can often be achieved in other ways. Certain C operations like use of `memcpy()` don't have a direct equivalent in Go, you have to work it around.

Proposed equivalent of 'sodium_free()' C function in golang based on different memory management concept::

func (canary []byte) sodiumFree(ptr unsafe.Pointer) {
    if ptr == nil {
        return
    }

    unprotected_ptr := unsafe.Pointer(uintptr(ptr) - unsafe.Sizeof(canary))
    base_ptr := uintptr(unprotected_ptr) - 2 * unsafe.Sizeof(canary)
    unprotectedSize := uintptr(base_ptr)
    total_size := 3 * unsafe.Sizeof(canary) + unprotectedSize

    if !bytes.Equal(getBytes(unprotected_ptr, int64(unsafe.Sizeof(canary))), canary) {
        outOfBounds()
    }

    sodiumMUnlock(unprotected_ptr, int(unprotectedSize))
    freeAligned(base_ptr, int(total_size))
}

// Additional helper methods required:
// Extract data from raw pointer
func getBytes(ptr unsafe.Pointer, len int64) []byte {
    var data []byte
    dataSliceHdr := (*reflect.SliceHeader)(unsafe.Pointer(&data))
    dataSliceHdr.Cap = int(len)
    dataSliceHdr.Len = int(len)
    dataSliceHdr.Data = uintptr(ptr)

    return data
}

// Sample method for outOfBounds functionality
func outOfBounds() {
    panic("Out of bounds")
}

// freeAligned needs some kernel interfacing. This is not clear how exactly this function works
func freeAligned(base_ptr uintptr, length int) {
    // Intentional implementation left blank. 
}

// This method also needs kernel level instructions / system interrupt!
func sodiumMUnlock(unprotected_ptr unsafe.Pointer, len int) {
    // Intentional implementation left blank.
} 

Keep in mind that dealing with memory pointers is always threatening for security and safety reasons. That's why modern high level languages are trying to abstract away this possibility, offering memory safety to the developers. 

Executing this Go code inside of a sandboxed function(Go routine) is suggested. Still make sure the rights and capability of the produced binary. Make sure they are conforming your own interest and duties on your system's security policy.