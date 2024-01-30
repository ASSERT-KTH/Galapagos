Unfortunately, the request cannot be completed due to inherent differences between C (especially with implementation-dependent attributes such as `mprotect`, tied to memory management) and Go - primarily Go's garbage collection and safety features and C's manual memory management, which make a direct translation preserving exactly the same semantics not possible. 

Here's a simplified semantic equivalent - but please be advised: **built-in** memory protection mechanisms and explicit unlocking of memory post-use seen in the C code are **not** present in the available paradigms for Go:

go
import (
	"bytes"
	"unsafe"
)

func sodium_free(ptr unsafe.Pointer) {
	if ptr == unsafe.Pointer(uintptr(0)) {
		return
	}
	
	canaryPtr := (*byte)(unsafe.Pointer(uintptr(ptr) - unsafe.Sizeof(canary)))

	// based on implementation of `_unprotected_ptr_from_user_ptr`
	unprotectedPtr := getUnprotectedPtr(ptr)
	
	// based on assumptions about the C code
	basePtr := unprotectedPtr - (2 * pageSize)
	
	unprotectedSize := make([]byte, unsafe.Sizeof(basePtr))
	copy(unprotectedSize, basePtr)

	totalSize := (pageSize * 2) + len(unprotectedSize) + pageSize

	mprotectReadwrite(basePtr, totalSize)
	if !bytes.Equal(canaryPtr, canary) {
		out_of_bounds()
	}

	// handling for bare Go implementation / mlock - native doesn't exist in pure Go
	// but check as per original logic may still needs to be executed
	if !bytes.Equal(unprotectedPtr[len(unprotectedSize):], canary) {
		out_of_bounds()
	}
  
	span := Span{Start: uintptr(unprotectedPtr), End: uintptr(unprotectedPtr) + uintptr(len(unprotectedSize))}
	sodium_munlock(span)
	_free_aligned(basePtr, totalSize)
}

Above code has presumed some unknown C functions and variables.
Note well that traditional raw memory operations found in the C code here (like verifying memory bounds and explicit unmapping) are unusual in Go due to its emphasis on automatic elimination of these most frequent causes of programming bugs.