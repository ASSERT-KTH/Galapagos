go
package main

import (
	"encoding/binary"
	"math"
)

func btcWrite32be(zp []byte, x uint32) {

	// Convert uint32 to bytes
	bs := make([]byte, 4)
	binary.BigEndian.PutUint32(bs, x)

	// Copy bytes to zp
	for i := 0; i < len(bs); i++ {
		zp[i] = bs[i]
	}
}
