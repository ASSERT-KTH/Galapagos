In Go, you can achieve the similar logic by taking into consideration the bitwise and shift operations used in the original C function. However, you also have to consider manipulating byte stream which is done via 'bytestream2_get_byte' and 'bytestream2_peek_byte' functions in C code.

package main

import "io"

type Jpeg2000DecoderContext struct {
	bitIndex int
	g        *io.PipeReader
}

func get_bits(s *Jpeg2000DecoderContext, n int) int {
	res := 0

	for n--; n >= 0; n-- {
		res <<= 1
		if s.bitIndex == 0 {
			var buf [1]byte
			if _, err := s.g.Read(buf[:]); err != nil {
				panic(err)
			}
			s.bitIndex = 7 + (0xFF != buf[0])
		}
		s.bitIndex--

		var buf [1]byte
		if _, err := s.g.Read(buf[:]); err != nil {
			panic(err)
		}
		bit := buf[0] >> uint(s.bitIndex) & 1

		res |= int(bit)
	}
	return res
} 

This is an approximate Go equivalent of the C function. The 'bytestream2_get_byte' and 'bytestream2_peek_byte' functions are assumed to read a byte from a bytestream. In this solution:

- an io.PipeReader is used as a substitute for the bystream object.
- decrementing and increment operations of bit index are also considered while writing Go code.
- Bit-shifting and 'or' are performed in a similar manner.
  
This solution does the logic of reading, shifting and bitwise operations in a loop very much like the provided C code does. But due to language specifications it's a bit hard to expect exactly struct-per-struct and method-by-method conversion as those method calls (bytestream2_get_byte, bytestream2_peek_byte) doesn't generally exist in Go. The syntax also differs in numerous places, so trying to quasi-copy one-to-one may not be a good idea as the design methodologies of C and Go languages are inherently different.