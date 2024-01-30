go
import (
	"log"
	"runtime"
	"unsafe"
)

func ldb_malloc(size uintptr) unsafe.Pointer {
	ptr := C.malloc(size)
	if ptr == nil {
		log.Fatalf("Error: unable to allocate memory")
		runtime.Goexit()
	}
	return ptr
}

NOTE: This function is not ideal for use in the typical Go application due to its use of unsafe and syscall packages. It contravenes Go's memory safety guarantees. It's better to use "make" or other memory approaches to achieve similar results without potential side effects. Only use this when you are clear about cgo (bind C and Go) and unsafe package usages.