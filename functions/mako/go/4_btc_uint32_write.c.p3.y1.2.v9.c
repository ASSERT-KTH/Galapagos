You can't use same function signature in Go as the point increment is not available in Go. Here is a semantically equivalent function with different function signature.

golang
import (
	"encoding/binary"
	"unsafe"
)

func btc_uint32_write(zp *[]byte, x uint32) *[]byte {
	if isBigEndian() {
		*zp = append(*zp, byte(x>>0))
		*zp = append(*zp, byte(x>>8))
		*zp = append(*zp, byte(x>>16))
		*zp = append(*zp, byte(x>>24))
		return zp
	} else {
		binary.LittleEndian.PutUint32(*zp, x)
		return zp
	}
}

func isBigEndian() bool {
	var i uint32 = 1
	var b = (*[4]byte)(unsafe.Pointer(&i))
	if b[0] == 1 {
		//LittleEndian
		return false
	} else {
		//BigEndian
		return true
	}
}

This implementation checks the system endianness and then decides how to handle given integers: if it is BigEndian system, the function will manually shift the bytes and output them to the required array. If system is small endian, we will just use the value as is.

This code uses the built-in "unsafe" package to determine system's type of endianness, "binary.LittleEndian.PutUint32" from the "encoding/binary" package puts the last 32bits representation of x to the pointer "zp". The "append" function is used to append the shifted byte onto the slice and "*zp" is used to deference the pointer for a write operation.