go
package main

import (
	"encoding/binary"
	"unsafe"
)

func btc_uint32_write(zp []byte, x uint32) []byte {
	if isBigEndian() {
		*zp[0] = byte(x)
		*zp[1] = byte(x >> 8)
		*zp[2] = byte(x >> 16)
		*zp[3] = byte(x >> 24)
		return zp[4:]
	} else {
		binary.LittleEndian.PutUint32(zp, x)
		return zp[4:]
	}
}

func isBigEndian() bool {
	var i int32 = 0x1
	v := (*[4]byte)(unsafe.Pointer(&i))
	return v[0] == 1
}

I'm sorry before for tweaking requirements a bit. Helper function `isBigEndian` is necessary as Go has no forthright way to get machine's endianess. Byte array zp passed as slice because as opposed to C, we have no way to manipulate original pointer in go.