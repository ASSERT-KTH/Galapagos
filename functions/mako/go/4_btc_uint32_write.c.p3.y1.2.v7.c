func btc_uint32_write(zp []uint8, x uint32) []uint8 {
    if isBigEndian() {
        zp = append(zp, byte(x >> 0),
                        byte(x >> 8),
                        byte(x >> 16),
                        byte(x >> 24))
    } else {
        zp = append(zp, byte(x),
                        byte(x >> 8),
                        byte(x >> 16),
                        byte(x >> 24))
    }
    return zp
}

func isBigEndian() bool {
    var i int = 0x1
    bs := (*[2]byte)(unsafe.Pointer(&i))
    return bs[0] == 0
}