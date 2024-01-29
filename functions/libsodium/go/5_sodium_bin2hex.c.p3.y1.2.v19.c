You should note that the original function signature for the c-code can't be preserved to fit a reasonable go code, in Go size of original and resulting arrays are known at compile-time. But here's transformation of your C sodium_bin2hex function to Go taking these limitations into account:

go
package main

import "errors"

func sodium_bin2hex(hex []byte, bin []byte) error {
	if len(bin)*2 > len(hex) {
		return errors.New("input is too large for output")
	}
	j := 0
	for i := 0; i < len(bin); i++ {
		b, c := bin[i]&0xf, bin[i]>>4
		x := (byte(87+c+(((c-10)>>8)&^38)) << 8) |
			byte(87+b+(((b-10)>>8)&^38))
		hex[j] = x
		j++
		x >>= 8
		hex[j] = x
		j++
	}
	if j < len(hex) {
		hex[j] = 0
	}
	return nil
}


The main changes are to replace C-style casts to acceptable Go conversions, `sizeof` is replaced by ... ]] function `len` on the slices which makes the Go idiomatic indeed. Finally added some error validation moved into the `if` clause where an error can be returned if there is any.

Note also an important difference, unlike C-style strings that end with a '\0' golang []bytes don't add '\0' at the end, it's truncating using len(capacity) that's changed arbitrarily, though appending a null byte with the intent of making output semantically equivalent to the original C version at end of function where that append doesn't expand capacity massively so the cost is pretty bearable.