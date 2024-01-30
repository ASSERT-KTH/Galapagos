In Go language, you can use the "binary" package from the standard library to achieve equivalent functionality. Here is an equivalent implementation in Go that covers both big endian and little endian.

Both implementations assume that the xp slice has at least 4 bytes, similar to the safety constraints in the C code provided.

Big endian platform:

go
import (
	binary "encoding/binary"
)

func btc_read32le(xp []byte) uint32 {
	return uint32(xp[0])|
		uint32(xp[1])<<8|
		uint32(xp[2])<<16|
		uint32(xp[3])<<24
}


Little endian platform:

go
import (
	binary "encoding/binary"
)

func btc_read32le(xp []byte) uint32 {
	return binary.LittleEndian.Uint32(xp)
}

Above function will crash with invalid memory address or nil pointer deference error if input slice doesn't have at least 4 bytes. Check the slice length or recover the panic to avoid crash.

This outputs the uint32 value built from the bytes taken from the xp byte slice. Note that this is LittleEndian order is chosen in the binary.LittleEndian.Uint32 helper but BigEndian order is handled manually in the say code.