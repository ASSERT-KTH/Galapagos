func btc_read32le(xp []byte) uint32 {
    if !isLittleEndian() {
        return uint32(xp[0]) |
            uint32(xp[1])<<8 |
            uint32(xp[2])<<16 |
            uint32(xp[3])<<24
    }
    return binary.LittleEndian.Uint32(xp)
}

func isLittleEndian() bool {
    var i int32 = 0x01020304
    u := *(*byte)(unsafe.Pointer(&i))
    return u == 0x04
}