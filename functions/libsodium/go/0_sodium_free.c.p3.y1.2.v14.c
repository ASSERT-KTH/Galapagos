It would be quite complex to accurately replicate this function in Go as it uses concepts specific to C like memory unions and pointer manipulations that can't quite be represented in the same way in Go. Also, there are some intrinsic C functions used in the function; the equivalent Go functions could behave differently. However, I'll try to give you a simple, generalized interpretation of this function based on your ask. Please note that you need to replace "page_size", "canary", "_unprotected_ptr_from_user_ptr" etc. with actual values or computations that might bring you the desired results. 

golang
import (
    "os"
)

func SodiumFree(ptr unsafe.Pointer) {
    var pixelSize uint
    var canary [256]byte
    var page_size uint
    page_size = 32  // For simulating the page_size, need to replace with actual logic

    if ptr == nil {
        return
    }

    canaryPtr := uintptr(ptr) - unsafe.Sizeof(canary)
    unprotectedPtr := getUnprotectedPtrFromUserPtrcanaryPtr((uintptr)(ptr))
    basePtr := unprotectedPtr - (uintptr)(page_size*2)

    unprotectedSize := *(*uintptr)(unsafe.Pointer(basePtr))
    totalSize := page_size + page_size + unprotectedSize + page_size

    // Need to find Go customized methods or logic that 
    // Will replicate _mprotect_readwrite()	 functionality


    if !bytes.Equal(canaryPtr[:], canary[:]) {
        log.Fatal("_out_of_bounds.")
        os.Exit(1)
    }

    if !bytes.Equal(unprotectedPtr[unprotectedSize:], canary[:]) {
        log.Fatal("_out_of_bounds.")
        os.Exit(1)
    }

    munlock(unprotectedPtr, unprotectedSize)
    freeAligned(basePtr, totalSize)
}

// Skelton method simulate sodium_munlock
func munlock(ptr uintptr, size uintptr) {
    //Platform-specific operations
    return
}

// Skelton method simulate _free_aligned
func freeAligned(ptr uintptr, size uintptr) {
    //Platform-specific operations
    return
}

// Skeleton function needs to replace with the actual logic -- generate unprotectedPtr
func getUnprotectedPtrFromUserPtr(ptr uintptr) uintptr {
	// Put the additional logic 
	return ptr
} 


Please note that:
Memory safety & manipulation: Go is not suited for byte-level memory management, but it is possible through the "unsafe" package. Unlike C, it's not recommended in normal Go programming because it bypasses Go's memory safety features.

Unmanaged resources: Package "unsafe" does not provide an equivalent for C's free() function, because Go uses managed memory: the GC automatically frees memory when it is no longer in use. Package "unsafe" does not offer a way to free variables.