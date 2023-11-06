func btc_write32be(zp []uint8, x uint32) {
    binary.BigEndian.PutUint32(zp, x)
}