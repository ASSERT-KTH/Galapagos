import "C"
import "unsafe"

func btc_memzero(ptr unsafe.Pointer, len C.size_t) {
	if len > 0 {
		C.memset(ptr, 0, len)

		// the volatile asm instruction in C tries to prevent some compilers optimization b/h
		// like removing the memset operation once it's confirmed the memory is not read again after being cleared. 
		// But Golang doesn't do such deep optimizations, so this line is not needed in Go.
	}
}