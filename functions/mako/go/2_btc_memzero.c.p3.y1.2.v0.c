package main

import "C"
import "unsafe"

func btc_memzero(ptr *C.char, len C.size_t) {
	if len > 0 {
		C.memset(unsafe.Pointer(ptr), 0, len)
	}
}