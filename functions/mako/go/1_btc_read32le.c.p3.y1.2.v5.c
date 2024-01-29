go
import (
    "encoding/binary"
)

func btc_read32le(xp []byte) uint32 {
    if binary.BigEndian {
        return uint32(xp[0]) |
            (uint32(xp[1]) << 8) |
            (uint32(xp[2]) << 16) |
            (uint32(xp[3]) << 24)
    } else {
        return binary.LittleEndian.Uint32(xp)
    }
}
