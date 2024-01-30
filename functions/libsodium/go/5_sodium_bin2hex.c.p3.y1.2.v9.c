Here's is the Go equivalent of the provided C function:

go
import (
	"errors"
)

func sodium_bin2hex(hex []byte, hex_maxlen int, bin []byte, bin_len int) ([]byte, error) {
	var i int
	var x uint
	var b, c int

	if bin_len >= int(^uint(0)>>1)/2 || hex_maxlen <= bin_len*2 {
		return nil, errors.New("problem with input sizes")
	}
	for i = 0; i < bin_len; i++ {
		c = int(bin[i] & 0xf)
		b = int(bin[i] >> 4)
		x = (uint)(87+c+(((c-10)>>8)&^38))<<8 |
			(uint)(87+b+(((b-10)>>8)&^38))
		hex[i*2] = byte(x)
		x >>= 8
		hex[i*2+1] = byte(x)
	}
	hex[i*2] = 0

	return hex, nil
}


This Go version of the function has byte slices instead of char arrays. It includes explicit conversion to `uint` and `int` when needed, and it uses the `New` function from the `errors` package to throw an error if input sizes do not match up. Also it returns both hex and error as by idiom in the Go programming language functions must return an error as their second return parameter if something went wrong during their execution.
