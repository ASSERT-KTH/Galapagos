Go
package main 

import (
	"errors"
)

// ErrSodiumMisuse represents an error when the provided sizes are erroneous or potentially unsafe.
var ErrSodiumMisuse = errors.New("sodium misuse")

// sodiumBin2hex transforms a binary representation to a hex representation.
func sodiumBin2hex(hex []byte, hexMaxLen int, bin []byte, binLen int) ([]byte, error) {
	if binLen >= int(^uint(0)>>1)/2 || hexMaxLen <= binLen*2 {
		return nil, ErrSodiumMisuse
	}

	var i uint
	var x uint
	var b uint
	var c uint

	for int(i) < binLen {
		c = uint(bin[i] & 0xf)
		b = uint(bin[i] >> 4)
		x = (uint(87+c+(((c-10)>>8)&^38)) << 8) | uint(87+b+(((b-10)>>8)&^38))
     		hex[i*2] = byte(x)
     		x >>= 8
		hex[i*2+1] = byte(x)
		i++
	}

	hex[i*2] = 0
	return hex, nil
}

The concept of the Go Program is the similar as the C++ Code given earlier. But due to few language restrictions and functionality difference. We transform code with Handling Errors It more explicitly which increases Go program reliability and understanding a lot easier.