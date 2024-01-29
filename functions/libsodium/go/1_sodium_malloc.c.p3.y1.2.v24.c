import "C"
import "unsafe"

const garbageValue = 0x1B

func SodiumMalloc(size C.size_t) unsafe.Pointer {
    ptr := C._sodium_malloc(C.size_t(size))
    if ptr == nil {
        return nil
    }

    floatSlice := (*[1 << 30]float32)(ptr)[:size:size]
    for i := range floatSlice {
        floatSlice[i] = garbageValue
    }

    return ptr
}