go
import "encoding/binary"

func btc_write32be(zp []byte, x uint32) {
	binary.BigEndian.PutUint32(zp, x)
}
