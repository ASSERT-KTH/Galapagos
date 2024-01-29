func btc_read32le(xp []byte) uint32 {
	if isBigEndian() {
		return uint32(xp[0])<<0 |
			uint32(xp[1])<<8 |
			uint32(xp[2])<<16 |
			uint32(xp[3])<<24
	} else {
		return binary.LittleEndian.Uint32(xp)
	}
}

func isBigEndian() bool {
	var i int32 = 0x01020304
	u := []byte(*(*string)(unsafe.Pointer(&i)))
	return u[0] == 1
}