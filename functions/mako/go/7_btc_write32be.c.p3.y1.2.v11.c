func btc_write32be(zp []byte, x uint32) {
    if isBigEndian() {
        binary.BigEndian.PutUint32(zp, x)
    } else {
        zp[0] = byte(x >> 24)
        zp[1] = byte(x >> 16)
        zp[2] = byte(x >> 8)
        zp[3] = byte(x)
    }
}

func isBigEndian() bool {
    num := 0x43424140
    bytes := (*[4]byte)(unsafe.Pointer(&num))
    return bytes[0] == '0'
}