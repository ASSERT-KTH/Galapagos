go
func btc_uint32_write(zp []byte, x uint32) []byte {
    if binary.BigEndian {
        zp[0] = byte(x)
        zp[1] = byte(x >> 8)
        zp[2] = byte(x >> 16)
        zp[3] = byte(x >> 24)
    } else {
        binary.LittleEndian.PutUint32(zp, x)
    }
    return zp[4:]
}
