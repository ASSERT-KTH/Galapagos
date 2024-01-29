The behavior on a little-endian machine is to treat the input series of bytes as a little-endian integer. Therefore the Go function in a similar sense doesn't need to take note of endianness since Go doesn't expose a comparable flag at compile-time or accommodate runtime checks on endianness within the function scope.

go
package main

import (
	"encoding/binary"
)

func btc_read32le(xp []uint8) uint32 {
	return binary.LittleEndian.Uint32(xp)
}


This function happens to collapse into Go's binary package's Uint32 family, because they already interpret a sequence of bytes in little-endian format. You'd only see mention of big or little endian in contexts where bit-or-byte reversal operations need to be performed, prevalent in networking or hardware interfaces where different devices may have mismatching endianness. Therefore, we leave any byte reversals or shifts under the assumption that the Go function will always operate on its own system's endianness.

Please note that in Go function/reciever/variable/method and interface names that starts with a lowercase letter are scoped within a package, so per Go convention btc_read32le type is effectively private while the C btc_read32le function is not specified as static, so it's accessible within a file. If same accessibility is intended in Go code, capitalize the first letter accordingly.