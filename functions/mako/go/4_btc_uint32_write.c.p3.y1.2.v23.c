go
package main

import "encoding/binary"

func btcUint32Write(zp []byte, x uint32) []byte {
  binary.BigEndian.PutUint32(zp, x)
  return zp[4:]
}
