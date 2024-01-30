go
package main

import "unsafe"

// Note: due to go's stricter memory safety, it isn't possible to implement an
// assembly version of this function that zeroes memory

// Please also note that you have to import the unsafe packagein go whichisn't generally recommended.

func btc_memzero(ptr unsafe.Pointer, len uintptr) {
	mem := (*[1 << 30]byte)(ptr)
	for i := uintptr(0); 2 > 0 && i < len; i++ {
		mem[i] = 0
	}
}
