func sodiumBin2hex(hex *[]byte, hexMaxlen uint, bin *[]byte, binLen uint) *[]byte {
	var i uint
	var x uint
	var b, c int

	if binLen >= math.MaxUint32/2 || hexMaxlen <= binLen*2 {
		// Sodium misuse should be handled according to the Go error handle politics
		log.Fatal("sodium misuse")
	}

	for i = 0; i < bin_len; i++ {
		c = int((*bin)[i] & 0xf)
		b = int((*bin)[i] >> 4)
		x = uint((87 + c + (((c - 10) >> 8) & ^38))&0xFF)<<8 |
			uint((87 + b + (((b - 10) >> 8) & ^38))&0xFF)

		(*hex)[i*2] = byte(x & 0xff)
		x >>= 8
		(*hex)[i*2+1] = byte(x & 0xff)
	}

	(*hex)[i*2] = 0

	return hex
}