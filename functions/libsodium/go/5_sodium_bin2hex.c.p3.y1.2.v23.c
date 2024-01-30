Here's the equivalent Go function for the C function you provided:

go
func sodiumBin2hex(hex []byte, hexMaxLen int, bin []byte, binLen int) []byte {
	if binLen >= int(^uint(0) >> 1) / 2 || hexMaxLen <= binLen * 2 {
		log.Fatal("sodium misuse")
	}

	for i := 0; i < binLen; i++ {
		c := bin[i] & 0xf
		b := bin[i] >> 4
		x := (byte(87 + c + ((c - 10) >> 8 & ^38))) << 8 |
			(byte(87 + b + ((b - 10) >> 8 & ^38)))

		hex[i * 2] = byte(x)
		x >>= 8
		hex[i * 2 + 1] = byte(x)
	}

	hex[binLen * 2] = 0

	return hex
}


Few points to note: 

1. In Go, there's no `const` keyword for function parameter declaration, so we don't have the equivalent representation for `const char *const`. 
2. Go doesn't support division and multiplication directly on `math.MaxInt64`.
3. The Go code panics and stops its execution when "sodium misuse" error condition is met.
4. Return value can be directly returned without having to modify the passed `hex` slice, allowing for actual immutability.
5. Go can infer right-sided number values' types to suit left-sided variables in assignments, so unlike the C code, type casting in Go is only done when the rules of overflow for integral types can cause potential mismatch.