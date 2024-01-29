Here is the implementation of above code in Go.

go
package main

import "fmt"

func sodiumBin2Hex(hex []byte, bin []byte) []byte {
	if len(bin) >= ((1<<63 - 1) / 2) || len(hex) <= len(bin)*2 {
		panic("sodium misuse")
	}

	for i := 0; i < len(bin); i++ {
		c := bin[i] & 0xf
		b := bin[i] >> 4
		x := (87 + int(c) + (((int(c) - 10) >> 8) & ^38))<<8 |
			(87 + int(b) + (((int(b) - 10) >> 8) & ^38))
		hex[i*2] = byte(x)
		x >>= 8
		hex[i*2+1] = byte(x)
	}
	hex[len(bin)*2] = 0

	return hex
}

func main() {
	bin_data := []byte{4, 7, 9}
	hex_data := make([]byte, len(bin_data)*2+1)
	
	res := sodiumBin2Hex(hex_data, bin_data)
	fmt.Println(res)
}

Please note that in Go language, You cannot pass the `hex_maxlen` and `bin_len` values explicitly as a function argument, because the length (`len()`) properties is utilized in the slices themselves. Moreover, size limit checks aren't always necessary because of the way slices work in Go. So, I omitted these two arguments in avoiding confusion, as they become redundant, and not useful. In Go, you use len and cap to get physical (allocated) and logical lengths of an array or a slice.

If you pass the hex and bin data slices to the sodium_bin2hex equivalent function written in Golang, the function will directly use Go's core len function to get the length. If the function was to use them, it wouldn't alter the functionality rather than confuse whoever was reading the code, so I modified the function to remove `hex_maxlen` and `bin_len`.