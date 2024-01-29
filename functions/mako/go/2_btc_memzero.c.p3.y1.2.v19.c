The equivalent function in Go might look as follows:

go
import "unsafe"

func btc_memzero(ptr unsafe.Pointer, len uintptr) {
    mem := (*[1 << 30]byte)(ptr)

    for i := uintptr(0); i < len; i++ {
        mem[i] = 0
    }
}


Here, pointers in Go are only allowed to byte-aligned or uintptr data. Variables of type Map, Func, Channel are not supported. Hence casting these values to uintptr and then to unsafe pointer cannot be done.