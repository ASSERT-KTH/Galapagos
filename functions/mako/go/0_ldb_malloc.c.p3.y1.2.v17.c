Go
import (
	"os"
	"unsafe"
)

func ldb_malloc(size uintptr) unsafe.Pointer {
	ptr, err := malloc(size)

	if err != nil {
		os.Exit(1)
	}

	return ptr
}

Please remember that memory allocation interfaces like above don't exist in Go like they do in languages like C, where malloc directly allocates a block of uninitialized memory. Go's memory allocation is performed with new or make, but these return initialized memory (zeroed for new, properly initialized for make), where internal bookkeeping fields are properly set up. Go's garbage collector might not like some ways you fiddle with unsafe.Pointer.

So the best way would handle this requirement in Go is

Go
func ldb_malloc(size int) []byte {
	mem := make([]byte, size)

	return mem
}
