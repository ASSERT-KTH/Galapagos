Here's a translation which tries to keep the original function's structure and logic intact. However, few assumptions were today due to lack of pre-defined objects in the question - `_unprotected_ptr_from_user_ptr` function's equivelant logic, the conversion equivelant code for C's `unsigned char *` and the implementation code for `_mprotect_readwrite`, `_out_of_bounds`, and `_free_aligned`.

go
func sodiumFree(ptr unsafe.Pointer) {
    if ptr == nil {
        return
    }

    var canary [24]byte // Assuming canary length similar to C definition, please change based on original Canari value
    var page_size uint16 = 4096 // Defined based on an average/default page size
    
    canaryPtr := uintptr(ptr) - uintptr(len(canary))
    unprotectedPtr := /*mapping logic for _unprotected_ptr_from_user_ptr*/0  // As its not defined how its converted to uintptr.
    basePtr := unprotectedPtr - uintptr(page_size * 2)
  
    var unprotectedSize uint64
    unfptrSize := unsafe.Pointer(&unprotectedSize)
    memoty.Copy(unfptrSize, unsafe.Pointer(basePtr)) // C's memcpy equivallent code in Go
    totalSize := uintptr(page_size * 2 + unprotectedSize + page_size)
   
   //_mprotect_readwrite function is not directly astablished in Go. An equivalent logic could be added here.
   
    var actualCanary [24]byte // As its values aren't defined, creating placeholder.
    if subtle.ConstantTimeCompare(*canaryPtr, *actualCanary) != 0 { 
        fmt.Println("_out_of_bounds") // Similar navigation logic for mprotect could be built.
    }  
    
#ifndef HAVE_PAGE_PROTECTION    // There's no preproccessor in Go programming. Hence, removing this part.
    if subtle.ConstantTimeCompare(*unprotectedPtr + uintptr(unprotectedSize), *actualCanary) != 0 {
        fmt.Println("_out_of_bounds")
    }
#endif

    if err := sodiumMUnlock(uintptr(ptr), uintptr(unprotectedSize)); err != nil {
        panic(fmt.Sprintf("sodiumMUnlock: Failed : %s", err))
    }
    
   // An equivalent logic to, mprotect utilization for De-allocation memory is not explicitly avaliable _
	equivalent funcrions include sys.Munmap in Unix ©mcall, not portable across systems.
}
