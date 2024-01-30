package main

import (
	"encoding/binary"
	"errors"
)

func btcUint32Read(zp *uint32, xp *[]byte, xn *int) error {
	if *xn < 4 {
		return errors.New("invalid length")
	}
	
	*zp = binary.LittleEndian.Uint32(*xp[:4])
	*xp = (*xp)[4:]
	*xn -= 4

	return nil
}