Based on the provided C code, here would be a Go equivalent:

go
package main

import (
	"encoding/binary"
)

func btc_uint32_read(zp *uint32, xp *[]byte, xn *int) bool {
	if *xn < 4 {
		return false
	}

    *zp = binary.LittleEndian.Uint32(*xp)

    *xp = (*xp)[4:]
    *xn -= 4
		
	return true
}


This version of the function in Go keeps as much fidelity to the C version as possible reusing bitwise shift operation as Go being a modern language provides built-in features that does automate part of what it is done manually in C.

Note: Please be aware that this Go code snippet might not professionally handlings endianness. Go has the `"encoding/binary"` package for conversion between byte sequences and numeric types but a bit more work would be involved should you need to dynamically change endianness, akin to setting the `BTC_BIG_ENDIAN` directive used in your C program.