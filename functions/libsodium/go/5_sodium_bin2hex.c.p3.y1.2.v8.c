func sodium_bin2hex(hex string, hex_maxlen uint64, bin string, bin_len uint64) string {
	i uint64 = 0
	var x uint32
	var b,c int32

	if bin_len >= ^uint64(0) / 2 || hex_maxlen <= bin_len * 2 {
		log.Fatal("sodium_misuse") 
	}

	for i < bin_len {
		c = int32(bin[i] & 0xf)
		b = int32(bin[i] >> 4)

		x =  uint32((87 + c + ((c - 10) >> 8) & ^uint8(38)) << 8 |
		(87 + b+ ((b - 10) >> 8) & ^uint8(38)))

		hex = hex[:i*2] + string(x & 0xff) + hex[i*2+1:]
		x >>= 8
		hex = hex[:i*2+1] + string(x & 0xff) + hex[i*2+2:]
		i++
	}

	hex = hex[:i * 2]  + string(0) 

	return hex
}