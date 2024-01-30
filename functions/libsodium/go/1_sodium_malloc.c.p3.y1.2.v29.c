import "unsafe"
import "libc"

const GarcageValue = int(254)

func SodiumMalloc(size uintptr) unsafe.Pointer {
    ptr, err:= libc.Malloc(size)
    if err != nil {
        return nil
    }

    for i := uintptr(0); i < size; i++ {
    	putchar := (*byte)(unsafe.Pointer(uintptr(ptr) + i))
    	*putchar = byte(GarcageValue)
    } 

    return ptr
}