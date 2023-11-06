As the operations performed in the original C code are checking for aligned memory and safeguarding against out-of-bounds accesses explicitly, which are automatically handled by the Go runtime, the exact translated function may look much simpler. Besides, C operates with pointers extensively, whereas Go discourages fine-grain pointer manipulations. Here's the equivalent Go function:

go
import "unsafe"

func SodiumFree(ptr unsafe.Pointer) {
	basePtr := uintptr(ptr)
	if basePtr == 0 {
		return
	}

	var unprotectedSize uint64
	unprotectedSizePointer := (*uint64)(unsafe.Pointer(uintptr(basePtr) - unsafe.Sizeof(unprotectedSize)))

	totalSize := *unprotectedSizePointer    

	unprotectedPtr := basePtr - uintptr(2) * unsafe.Sizeof(totalSize)
	_, _, err := syscall.Syscall(syscall.SYS_MUNLOCK,
	uintptr(unsafe.Pointer(uintptr(unprotectedPtr))),
	uintptr(totalSize), 0)

	if err != 0 {
		log.Panicln("MUNLOCK failed", err)
	}

	C.free(uintptr(unsafe.Pointer(basePtr)))
}


Some assumptions:
1. This function call C.free(), assuming cgo is invoked to use C's standard libs. Please add `import "C"`
2. As we require syscall, import "syscall".
3. page_size is presumed to use unsafe.Sizeof(freeSizePointer) for demonstration purposes.
4. If addressing cleanup or failure logging is required based on the process responses, please import "log" package too.
5. 'canary', _unprotected_ptr_from_user_ptr(), _mprotect_readwrite(), sodium_memcmp(), sodium_munlock() and _free_aligned() could not be translated accurately due to the lack of mapping in Go. If context about canary is required or more about these function needs to be converted, more context would be needed about these APIs.