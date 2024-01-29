go
import "unsafe"
import "reflect"

func SodiumMemZero(pnt unsafe.Pointer, len uintptr) {
    b := *(*[]byte)(unsafe.Pointer(&reflect.SliceHeader{
        Data: uintptr(pnt),
        Len:  int(len),
        Cap:  int(len),
    }))
    for i := range b {
        b[i] = 0
    }
}
