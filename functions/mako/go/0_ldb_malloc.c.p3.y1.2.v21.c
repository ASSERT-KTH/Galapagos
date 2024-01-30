go
import (
	"os"
	"unsafe"
)

func ldbMalloc(size uintptr) unsafe.Pointer {
	ptr, err := C.malloc(C.size_t(size))
	if ptr == nil {
		panic(err)
	}
	return ptr
}
