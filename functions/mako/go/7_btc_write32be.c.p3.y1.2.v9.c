func btc_write32be(zp []uint8, x uint32) {
    zp[0] = uint8(x >> 24)
    zp[1] = uint8(x >> 16)
    zp[2] = uint8(x >> 8)
    zp[3] = uint8(x >> 0)
}