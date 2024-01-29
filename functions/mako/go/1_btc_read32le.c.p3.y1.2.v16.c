go
import (
    "encoding/binary"
)

func btc_read32le(xp []byte) uint32 {
    return binary.LittleEndian.Uint32(xp)
}
