The function you provided works with low-level manipulation of binary interpretation of numbers in C, which doesn't directly translate to high-level static typed Go programming language. Therefore, you can work around via `binary` package in Golang as follows.

go
import (
    "encoding/binary"
    "unsafe"
)

func btcUint32Write(zp *[]byte, x uint32) {
	const INT_SIZE uint32 = uint32(unsafe.Sizeof(0))
	*orig := *zp
    *zp = orig[:INT_SIZE+uint32(len(orig))]
    if IsLittleEndian() {
		var b [4]byte
        binary.LittleEndian.PutUint32(b[:], x)
        copy(zp, b[:])
    } else {
        var b [4]byte
        binary.BigEndian.PutUint32(b[:], x)
        copy(zp, b[:])
    }
}


Please note that `unsafe.Sizeof(x))` must be const integer in (or can be converted to) `int`. For determining endianness, we can use following `IsLittleEndian`.

go
func IsLittleEndian() bool {
    var i int = 0x1
	bs := (*[4]byte)(unsafe.Pointer(&i))
	return bs[0] == 1
}
 

I am aware this goes attempt does not exactly replicate the C function, the semantics are as close as is reasonable (the C function used pointer arithmetic for offsets, whereas manual indexing is required in Go, due to strong duck-typing).