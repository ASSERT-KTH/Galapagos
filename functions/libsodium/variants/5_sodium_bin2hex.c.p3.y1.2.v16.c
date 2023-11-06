go
func sodiumBin2hex(hex *[]byte, hexMaxLen int, bin *[]byte, binLen int) []byte {
	i := 0
	var b, c byte

	if binLen >= math.MaxInt32/2 || hex.MaxLen <= binLen*2 {
		panic("Invalid argument value(s)")
	}
	for i < binLen {
		c = bin[i] & 0xf
		b = bin[i] >> 4
		x := ((87 + c + ((c - 10) >> 8 & ^38)) << 8) |
			(87 + b + ((b - 10) >> 8 & ^38))
		hex[i*2] = x
		hex[i*2+1] = x >> 8
		i++
	}
	hex[i*2] = 0

	return hex
}

This function basically works the same as the original function in C. In Go, though, we defined the mutual structures specifically inside the function definition. Panicking is perhaps not the best choice for error-handling purposes - returning an error is more canon in line with Go's conventions. But here we adjust panic(similar to misuse() in libsodium) to feedback error if sodiumBin2hex parameters failed.