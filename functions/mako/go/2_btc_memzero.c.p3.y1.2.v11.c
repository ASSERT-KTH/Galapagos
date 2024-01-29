import "C"

import "unsafe"
import "reflect"

func btc_memzero(ptr unsafe.Pointer, len uint) {
    var s reflect.SliceHeader
    s.Data = uintptr(ptr)
    s.Len = int(len)
    s.Cap = int(len)
    b := *(*[]byte)(unsafe.Pointer(&s))
    for i := range b {
	    b[i] = 0
    }
}