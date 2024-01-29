Here's one way to create a semantically equivalent version in Go:

go
import (
    "encoding/binary"
    "bytes"
)

func btc_write32be(zp []byte, x uint32) {
    binary.BigEndian.PutUint32(zp, x)
}
