go
func btc_write32be(zp []byte, x uint32) {
	binary.BigEndian.PutUint32(zp[0:], x)
}
