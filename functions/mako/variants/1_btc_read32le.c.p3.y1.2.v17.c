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
    var i uint32 = 0x01020304
    u := []byte{ byte(i),  byte(i >> 8), byte(i >> 16),  byte(i >> 24)}
    return u[0] == 0x01
}