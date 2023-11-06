func btc_read32le(xp []byte) uint32 {
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
    var x uint32 = 0x12345678
    littleEndian := (*[4]byte)(unsafe.Pointer(&x))[0] == 0x78
    return !littleEndian
}