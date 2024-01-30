go
package main

import (
	"encoding/binary"
    "bytes"
)

func btcUint32Write(zp []byte, x uint32) []byte {
	buf := new(bytes.Buffer)
	// If BTC_BIGENDIAN is defined, x is shifted and pushed to buf in BigEndian order
	binary.Write(buf, binary.BigEndian, x)
	// Copy data from buf to zp
	copy(zp, buf.Bytes())
	// Returns zp incremented by 4 (sizeof(uint32) = 4bytes)
	return zp[4:]
}

Full translation of original C function into a Go function including endianess check is unfortunately not possible as Go doesn't allow conditional compilations (like defining macros BTC_BIGENDIAN in C). Therefore this Go code always behaves as if BTC_BIGENDIAN was not defined.