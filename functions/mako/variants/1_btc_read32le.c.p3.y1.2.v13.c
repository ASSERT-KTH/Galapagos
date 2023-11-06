func btc_read32le(xp []byte) uint32 {
	var z uint32
	if isBigEndian() {
		z = uint32(xp[0]) | uint32(xp[1])<<8 | uint32(xp[2])<<16 | uint32(xp[3])<<24
	} else {
		z = binary.LittleEndian.Uint32(xp)
	}
	return z
}

func isBigEndian() bool {
	var i int32 = 0x01234567
	u := unsafe.Pointer(&i)
	pb := (*byte)(u)
	b := *pb 
	return (b == 0x01)
}