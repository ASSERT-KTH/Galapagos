import (
	"os"
	"unsafe"
)

func btc_free(ptr unsafe.Pointer) {
	if ptr == nil {
		os.Exit(1)
	}

	C.free(ptr)
}