go
import (
	"log"
	"unsafe"
)

func ldb_malloc(size uintptr) unsafe.Pointer {
	ptr, err := C.malloc(C.size_t(size))
	if err != nil {
		log.Fatalf("Failed to allocate memory: %v", err)
	}

	return unsafe.Pointer(ptr)
}
