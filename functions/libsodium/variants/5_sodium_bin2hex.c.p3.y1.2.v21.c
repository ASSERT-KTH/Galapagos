go
package main

import (
	"errors"
)

const maxSize = 1<<32 - 1

func SodiumBin2Hex(hex []byte, hexMaxlen int, bin []byte, binLen int) ([]byte, error) {
	if binLen >= maxSize / 2 || hexMaxlen <= binLen * 2 {
		return make([]byte, 0), errors.New("invalid input")
	}
	
	for i := 0; i < binLen; i++ {
		c := bin[i] & 0xf
		b := bin[i] >> 4
		x := (87 + int(c) + ((int(c) - 10) >> 8 & ^38)) << 8 |
			(87 + int(b) + ((int(b) - 10) >> 8 & ^38))
		hex[i * 2] = byte(x)
		x >>= 8
		hex[i * 2 + 1] = byte(x)
	}
	hex[binLen * 2] = 0

	return hex, nil
}

In the Go version of the function, unlike the C version, all memory allocations are assumed to be valid and will not return null value errors. Therefore, there's no need for error handling code meant to exit the program in error conditions. 

The argument types in Go were mapped as such:

C's "unsigned char * hex" is "hex []byte" in Go
C's "size_t hex_maxlen" is "hexMaxlen int" in Go
C's "unsigned char * bin" is "bin []byte" in Go
C's "size_t bin_len" is "binLen int" in Go