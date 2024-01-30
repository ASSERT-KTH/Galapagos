package main

import (
	"unsafe"
)

// Go doesn't have volatile or asm, so we can't zero memory to prevent GC and compiler optimizing it out.

func btcMemset(ptr unsafe.Pointer, len uintptr) {
    *(*[1 << 40]byte)(ptr)[:len] = [len]byte{}
}