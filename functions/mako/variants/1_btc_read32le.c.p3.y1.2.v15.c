func btc_read32le(xp []byte) uint32 {
    if isBigEndian() {
        return uint32(xp[0])<<0 | uint32(xp[1])<<8 | uint32(xp[2])<<16 | uint32(xp[3])<<24
    } else {
        z := binary.LittleEndian.Uint32(xp)
        return z
    }
}

func isBigEndian() bool {
    var i int32 = 0x1
    b := (*[4]byte)(unsafe.Pointer(&i))
    return b[0] == 0
}