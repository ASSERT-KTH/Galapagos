import "C"
import "unsafe"

// #include <string.h>

func btc_memzero(ptr unsafe.Pointer, len C.size_t) {
	if len > 0 {
		C.memset(ptr, 0, len)
	}
}