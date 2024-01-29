go
import (
	"encoding/binary"
)

func btc_read32le(xp []uint8) uint32 {
	if isBigEndian() {
		return uint32(xp[0]) |
			uint32(xp[1])<<8 |
			uint32(xp[2])<<16 |
			uint32(xp[3])<<24
	} else {
		return binary.LittleEndian.Uint32(xp)
	}
}

func isBigEndian() bool {
	var i int32 = 0x01234567
	u := (*[4]byte)(unsafe.Pointer(&i))
	return u[0] == 1
}
