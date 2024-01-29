import "C"

import (
	"unsafe"
)

//export sodium_memzero
func sodium_memzero(pnt unsafe.Pointer, len C.size_t) {
	// C.go_memset is a wrap C memset
	C.go_memset(pnt, 0, len)
}