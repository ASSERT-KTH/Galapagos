import "C"
import "unsafe"

// #cgo windows CFLAGS: -DWIN32
// #cgo CFLAGS: -DHAVE_EXPLICIT_BZERO
// //Windows
// #cgo windows LDFLAGS: -lssp
// //Unix
// #cgo LDFLAGS: -lc
// #include <string.h>
import "C"

func Sodium_memzero(pnt unsafe.Pointer, len C.size_t) {
	_Ctype_void := pnt
	_Ctype_size_t := len
	C.ZeroMemory(_Ctype_void, _Ctype_size_t)
	C.explicit_bzero(_Ctype_void, _Ctype_size_t)
}