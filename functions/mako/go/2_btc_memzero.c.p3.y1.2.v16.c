import "unsafe"
import "reflect"

func btc_memzero(ptr unsafe.Pointer, len uintptr) {
	ptrSlice := (*(*[1<<40]byte)(ptr))[0:len]
	p := reflect.ValueOf(ptrSlice).Pointer()
	mem := (*[0x7fffffff]byte)(unsafe.Pointer(p))

	for i := range mem[:len] {
		mem[i] = 0
	}
}