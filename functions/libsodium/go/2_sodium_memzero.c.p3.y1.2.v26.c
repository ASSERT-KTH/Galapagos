Here is a equivalent function of "sodium_memzero" in Go:

go
import "unsafe"
import "reflect"

func sodium_memzero(pnt unsafe.Pointer, len uintptr) {
    var b []byte
    hdr := (*reflect.SliceHeader)(unsafe.Pointer(&b))
    hdr.Data, hdr.Len, hdr.Cap = uintptr(pnt), int(len), int(len)
    for i := range b {
        b[i] = 0
    }    
}
