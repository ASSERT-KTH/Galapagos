package main

import "C"

func btc_memzero(ptr unsafe.Pointer, len uintptr) {
   C.memset(ptr, 0, len)
}
