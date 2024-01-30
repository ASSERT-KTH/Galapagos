go
import (
    "unsafe"
    "reflect"
)

func btc_memzero(ptr unsafe.Pointer, len int) {
	zero := make([]byte, len)
	var valueSlice reflect.SliceHeader
	valueSlice.Data = uintptr(ptr)
	valueSlice.Len = len
	valueSlice.Cap = len
	copy(*(*[]byte)(unsafe.Pointer(&valueSlice)), zero)
	return
}

Please note that Go is intentionally built to avoid raw pointer manipulation. This is considered unsafe and non-idiomatic Go code but represent the semantic equivalent translation from the original C version. It's better to handle such memory/object cleanup within the context of Go's garbage collection system, which is designed to avoid such manual management issues. Remember to enjoy the benefits of the Go's garbage collector!