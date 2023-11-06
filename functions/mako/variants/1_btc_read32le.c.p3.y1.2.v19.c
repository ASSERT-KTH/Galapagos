go
import (
	"encoding/binary"
)

func btc_read32le(xp []uint8) uint32 {
	return binary.LittleEndian.Uint32(xp)
}
