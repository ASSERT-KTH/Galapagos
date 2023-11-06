go
package main

import (
	"encoding/binary"
)

func read32le(xp []byte) uint32 {
    return binary.LittleEndian.Uint32(xp)
}
