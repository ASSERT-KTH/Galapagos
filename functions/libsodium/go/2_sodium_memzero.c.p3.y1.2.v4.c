go
package main

import "C"
import "unsafe"

// void sodium_memzero(void * const pnt, const size_t len)

func sodium_memzero(pnt unsafe.Pointer, len C.size_t) {

	ptr := (*[1 << 30]byte)(pnt)

	for i := 0; i < int(len); i++ {
		ptr[i] = 0
	}
}
