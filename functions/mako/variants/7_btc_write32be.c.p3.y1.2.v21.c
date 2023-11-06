package main

import (
	"encoding/binary"
	"fmt"
)

func btc_write32be(zp []byte, x uint32) {
	binary.BigEndian.PutUint32(zp, x)
}

func main() {
	zp := make([]byte, 4)
	x := uint32(123456789)
	btc_write32be(zp, x)
	fmt.Println(zp)
}