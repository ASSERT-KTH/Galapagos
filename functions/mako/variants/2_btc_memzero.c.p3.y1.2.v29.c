// Golang does not support inline assembly or have a direct equivalent to memset. Therefore, a simple loop is used to set the memory to zero. Cgo and unsafe.Pointer are used to facilitate this.

/*
#include "stdlib.h"

void btc_memzero(void *ptr, size_t len) {
	if (len > 0) {
		memset(ptr, 0, len);
        asm volatile(
            ""
            :: "r"(ptr)
            : "memory");
	}
}
*/
import "C"
import "unsafe"

func btc_memzero(ptr unsafe.Pointer, len C.size_t) {
	for i := 0; i < int(len); i++ {
		p := (*byte)(unsafe.Pointer(uintptr(ptr) + uintptr(i)))
		*p = 0
	}
}