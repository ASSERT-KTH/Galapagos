Go
package main

import (
	"encoding/binary"
	"reflect"
)

func btc_write32be(zp []byte, x uint32) {
	if reflect.TypeOf(x).Kind() == reflect.Uint32 {
		binary.BigEndian.PutUint32(zp, x)
	} else {
		zp[0] = byte(x >> 24)
		zp[1] = byte(x >> 16)
		zp[2] = byte(x >> 8)
		zp[3] = byte(x >> 0)
	}
}
