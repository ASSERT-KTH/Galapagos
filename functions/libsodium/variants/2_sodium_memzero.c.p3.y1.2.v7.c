Here is the semantically equivalent version of the function in Go.

go
import (
	"unsafe"
	"reflect"
)

func sodium_memzero(pnt unsafe.Pointer, len uintptr) {
	b := (*[1<<30]byte)(pnt)[:len:len]
	for i := range b {
		b[i] = 0
	}

	i := 0
	ptr := reflect.ValueOf(pnt).Pointer()
	hdr := reflect.SliceHeader{Data: ptr, Len: int(len), Cap: int(len)}
	b = *(*[]byte)(unsafe.Pointer(&hdr))

	for i := 0; i < len; i++ {
        b[i] = 0
    }
}

Note: This implementation uses the Go standard library packages for handling unsafe pointers and reflect package for creating a slice data structure without runtime assertion for understandable memory overwrite, instead of platform specific C low-level libraries (like `memset_s`, `explicit_bzero`... etc used in the original C version). While storage is filled with `0U` (`0`) over the specified `len (length)` starting from `pnt (memory location)`, due to restrictions of Go’s safety-oriented approach, which prevents memory modification provided by those packages, avoid direct mappings if converting code from C into Go as was performed in the example above.