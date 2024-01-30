import "C"
import "unsafe"

// #cgo CFLAGS: -g -O2
// #include <string.h>
// #include <windows.h>
// #include <stdio.h>
//
// void btc_memzero(void *ptr, size_t len);

func btc_memzero(ptr unsafe.Pointer, len C.size_t) {

	if len > 0 {
		C.memset(ptr, 0, C.size_t(len))

		C.__asm__ __volatile__ (
			""
				:: "r" (ptr)

				: "memory"
		)
	}

	elseif len > 0 {
		C.SecureZeroMemory(ptr, len)
	}

	else {
		C.memset(ptr, 0, C.size_t(len))
	}
}