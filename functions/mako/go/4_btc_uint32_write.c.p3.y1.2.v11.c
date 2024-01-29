
func btc_uint32_write(zp *[]byte, x uint32) *[]byte {
    if binary.BigEndian {
        *zp = append(*zp, byte(x >> 0))
        *zp = append(*zp, byte(x >> 8))
        *zp = append(*zp, byte(x >> 16))
        *zp = append(*zp, byte(x >> 24))
    } else {
        buf := make([]byte, 4)
        binary.LittleEndian.PutUint32(buf, x)
        *zp = append(*zp, buf...)
    }
    return zp
}
