Here is a translation in Go:

go
import (
    "encoding/binary"
)

func btc_read32le(xp []byte) uint32 {
    if isBigEndian() {
        return uint32(xp[0])<<0 |
            uint32(xp[1])<<8 |
            uint32(xp[2])<<16 |
            uint32(xp[3])<<24
    } else {
        return binary.LittleEndian.Uint32(xp)
    }
}

func isBigEndian() bool {
    var i int32 = 0x1
    u := (*[4]byte)(unsafe.Pointer(&i))
    return u[0] == 1
}


Please take note that I used this `isBigEndian` function to substitute `#if defined(BTC_BIGENDIAN)` from the original C version. This is because in Go we tool that checks for system's endianness at run-time, whereas in C preprocessor directives like `#if defined(BTC_BIGENDIAN)` are evaluated at compile-time. So, while this approach does make the function technically non-pure in terms of inputs and outputs, this is a pretty standard way to safely detect endianness in Go.