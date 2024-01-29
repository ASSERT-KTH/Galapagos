The function signature in this translation is "btc_read32le(xp []byte) uint32"

go
package main

import (
	"bytes"
	"encoding/binary"
)

func btc_read32le(xp []byte) uint32 {
	var num uint32
	buf := bytes.NewBuffer(xp[0:4])
	binary.Read(buf, binary.LittleEndian, &num)
	return num
}
