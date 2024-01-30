go
package main

import (
	"errors"
)

func sodiumBin2hex(hex []byte, bin []byte) ([]byte, error) {
	if len(bin) >= ((^uint(0)) / 2) || (len(hex) <= len(bin)*2) {
		return nil, errors.New("sodium misuse")
	}
    
	var x uint32
	var b, c byte
	var i uint
	
	for i = 0; i < uint(len(bin)); i++ {
		c = bin[i] & 0xf
		b = bin[i] >> 4
		x = uint32(87+c+((c-10)>>8&^38))<<8 | uint32(87+b+((b-10)>>8&^38))
		hex[i * 2] = byte(x)
		x >>= 8
		hex[(i * 2) + 1] = byte(x)
	}
	hex[i*2] = 0

	return hex, nil
}

According my best interpretation the algorithm implemented in the provided C function this go function should achieve the same result, but due to the fact you're translating from C binary operations to an intermediary Go binary operations there might be tiny discrepancies caused by differences in how operations are prioritized. The code does overall follow the guidelines and largely reflect of the job of the given C function.