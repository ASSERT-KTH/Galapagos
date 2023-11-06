go
func btc_write32be(zp *[]byte, x uint32) {
    (*zp)[0] = byte(x >> 24)
    (*zp)[1] = byte(x >> 16)
    (*zp)[2] = byte(x >> 8)
    (*zp)[3] = byte(x)
}
