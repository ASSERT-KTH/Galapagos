go
package main

import (
	"encoding/binary"
	"fmt"
)

func btcUint32Read(zp *uint32, xp **[]byte, xn *int) bool {
	if *xn < 4 {
		return false
	}

	switch *(*xp)[0]&(1<<7)>0 {
	case true: // big endian
		*zp = binary.BigEndian.Uint32(*xp)
	default:
		*zp = binary.LittleEndian.Uint32(*xp)
	}

	*xp = &(*(*xp)[4:])
	*xn -= 4

	return true
}
