go
import (
	"encoding/binary"
	"unsafe"
)

func btc_uint32_write(zp *[]byte, x uint32) *[]byte {
	z := (*[4]byte)(unsafe.Pointer(&x))
	if isBigEndian() {
	    *zp = append(*zp, (*z)[0], (*z)[1], (*z)[2], (*z)[3])
	} else {
	    *zp = append(*zp, (*z)[3], (*z)[2], (*z)[1], (*z)[0])
	}
	return zp
}

func isBigEndian() bool {
    var x uint32 = 0x01020304
    if *(*byte)(unsafe.Pointer(&x)) == 0x01 {
        return true
    }
    return false
}

The implementation checks if the system is big endian or not and sets bytes accordingly.
The concept of pointers in C is used where instead the slice references are used in Go.
As append mechanic works differently to writing directly to a pointer location, there is no need to increment anything. The append function of slices helps to keep track of the correct position on its own.
Last note is mentioning use of unsafe package in go in the implementation.
Unsafe package in go allows to perform low-level programming that bypasses the language's usual safety protections.
It should be used sparingly and only when directly dealing with operating systems, file systems, etc. as it may lead to code safety issues.
It can have varying consequences on different systems architecture hence accuracy when used is critical. 
The `unsafe.Pointer` is essential as go does not allow direct memory access unlike C. Here it uses it to interpret addresses of variables as byte pointers.