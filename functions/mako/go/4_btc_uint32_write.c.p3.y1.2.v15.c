go
import (
    "encoding/binary"
)

func btc_uint32_write(zp []byte, x uint32) []byte {
    binary.BigEndian.PutUint32(zp, x)
    return zp[4:]
}
