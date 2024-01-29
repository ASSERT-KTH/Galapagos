You can't exactly preserve the function's signature because Go doesn't support reference parameters or variable functions parameters. But you can make a function called SodiumBin2Hex that takes in a byte slice, bin, as its only parameter. If you want an equivalent compatibility with the constraints of C implementation (taking care of hex lenght), you'd have to modify the usage patterns a bit in Go, but the conversion logic can be absolutely equivalent. Returns the result as a hexadecimal-encoded string.

go
package main

import (
	"errors"
)

func sodiumBin2Hex(bin []byte) (string, error) {
	if len(bin) == 0 {
		return "", errors.New("binary data is empty")
	}

	hex := make([]byte, len(bin)*2)

	for i, val := range bin {
		c := val & 0xf
		b := val >> 4
		binaHex := func(b byte) byte { return 87 + b + ((b - 10) >> 8 & ^38) }

		x := binaHex(c) + binaHex(b)<<8

		hex[i*2] = x >> 8
		hex[i*2+1] = x & 0xff
	}

	return string(hex), nil
}

Note: 
The use of error handling here instead of C style runtime abort by `sodium_misuse()`. Also directly using addition and the shift operator to concatenate both bytes rather than the inefficient coercing and binary-or of C code. The logic of `sodium_bin2hex` is kept 1:1 in the lambda `binaHex` generating the corresponding ascii value for hex. Please take care while using the function as Go is UTF-8 by default and the code is implied by bytes.