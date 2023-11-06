Go
import (
    "encoding/binary"
)

func btc_read32le(xp []byte) uint32 {
    var z uint32
    if binary.BigEndian.Uint16([]byte{1, 0}) == 1 { // Little-endian machine
        z = binary.LittleEndian.Uint32(xp)
    } else { // Big-endian machine
        z = uint32(xp[0]) |
            uint32(xp[1])<<8 |
            uint32(xp[2])<<16 |
            uint32(xp[3])<<24
    }
    return z
}
