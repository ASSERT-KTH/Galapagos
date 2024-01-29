Here is a code snippet that uses golang's "unsafe" and "syscall" packages to map to the behavior of sodium library. However, it is not fully equivalent: There is no direct built-in equivalent of C's mprotect or munlock in Golang, also directly manipulations and casting of void pointers is not idiomatic in Go.

go
// unsafe and syscall are needed only to implement lower level
// manipulation of memory like the C version is doing
// which is not typically idiomatic go
import (
	"unsafe"
	"syscall"
)

const (
	pageSize = 4096  // Replace this with actual pageSize
	err      = -1    // Replace this with actual value when using with syscall
	canary   = ""    // Replace this with actual canary value
)

func SodiumFree(ptr unsafe.Pointer) {
	basePtr := unsafe.Pointer(uintptr(ptr))
	canaryPtr := unsafe.Pointer(uintptr(ptr) - unsafe.Sizeof(canary))
	unprotectedPtr := (*[1<<40 - 1]byte)(ptr) // User need to define a method to calculate unprotectedPtr

	unprotectedSize := uintptr(unsafe.Pointer(&basePtr))
	totalSize := pageSize + pageSize + unprotectedSize + pageSize

	_, _, errno := syscall.Syscall(syscall.SYS_MPROTECT, uintptr(basePtr), totalSize,
		syscall.PROT_READ|syscall.PROT_WRITE)

	if errno != 0 {
		panic("mprotect failed: error number " + string(errno))
	}

	if &canaryPtr == unsafe.Pointer(&canary) {
		// equivalent of _out_of_bounds()
		panic("_out_of_bounds called due to canary compare match.")
	}

	// Golang does not provide low level functions like munlock, use similar functionality available
	// in go. Below is a stub and not working call
	err = syscall.Munlock(uintptr(basePtr), int(unprotectedSize))

	freeAligned(ptr, totalSize)
}

Please note that doing low level memory manipulation like above is not recommended and against the idioms of Go language. Converting C function like above with direct pointer manipulation and function related to accessing OS facilities is ripe with platform compatibility issues, unsafe behaviours and error possibilities. Use higher level memory architectures and programming patterns provided by go is recommended.

Also, the libc sodium library has multiple bindings available for Golang, so chances are you can find your operation already implemented in one of those rather than direct clone of C code which often would not behave as you'd expect due to language differences (e.g., garbage collector in Go, lack of void pointers, etc.).