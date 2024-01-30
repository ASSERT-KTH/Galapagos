go
import (
    "encoding/binary"
)

func btcRead32le(xp []byte) uint32 {
    if binary.BigEndian {
        return uint32(xp[0]) |
            uint32(xp[1])<<8 |
            uint32(xp[2])<<16 |
            uint32([3])<<24
    } else {
        return binary.LittleEndian.Uint32(xp)
    }
}


Note: Go has a built-in package `binary` for binary data manipulation includes LittleEndian and BigEndian which implementRead, Write, and the Sizeof, Alignof, and Offsetof functions. The use of this module abstracts most of the specific details found in the C implementation. Furthermore, there is no implicit boolean conversion for non-boolean values, data type checks has to be implemented explicitly in Go.