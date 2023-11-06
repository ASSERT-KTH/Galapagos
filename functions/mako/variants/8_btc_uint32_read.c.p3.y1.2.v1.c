package main

import (
  "encoding/binary"
  "errors"
)

func btc_uint32_read(zp *uint32, xp *[]byte, xn *int) (bool, error) {
    
    if *xn < 4 {
        return false, errors.New("not enough data")
    }

    yourByteSlice := *xp

    *zp = binary.BigEndian.Uint32(yourByteSlice[0:4])
    
    newXpData := yourByteSlice[4:]
    *xp = newXpData
    newContentsCap := len(*xp)
    *xn = newContentsCap
    return true, nil
}