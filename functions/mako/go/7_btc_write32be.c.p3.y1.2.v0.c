go
import (
    "encoding/binary"
)

func btcWrite32be(zp []byte, x uint32) {
    binary.BigEndian.PutUint32(zp, x)
}
