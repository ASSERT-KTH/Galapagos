In Go, the same can be written as below:

go
package main

type Jpeg2000EncoderContext struct {
	buf       *[]byte
	bit_index int
}

func putBits(s *Jpeg2000EncoderContext, val int, n int) {
	for n--; n >= 0; n-- {
		if s.bit_index == 8 {
			if (*s.buf)[0] == 0xff {
				s.bit_index = 1
			} else {
				s.bit_index = 0
			}
			s.buf = &[]byte{0}
		}
		(*s.buf)[0] |= byte(val << (7 - s.bit_index))
		s.bit_index++
	}
}

This Go code goes through the given number of bits `n`, checks if the current bit_index(which indicates the current position within a byte to set the bit to) in the `Jpeg2000EncoderContext.` If it is 8 i.e., end of our byte, it adds a new byte. And for each bit it sets the bit at (7 - bit_index) position.

 Go is zero-indexed byte-based while C is one-indexed, so the translation does adapt to Go's indexes specifically the adjustment to index calculation methods. Also, C code handles pointers heavily. When we translate the pointers to Go, we need to use Slice and can achieve semantically similar effects by directly allocating new Slices and referencing existing ones. 

Note: Do keep in mind Go disposes of 'unused' heap allocations once out of scope when using programs such as those found in its 'net'.

A proper testing of this function would require an associated `Jpeg2000EncoderContext` that intended to be “realistically” mutated; The presented C function presents code clearly expected to exist in a larger system. Functional testing would potentially use sectorized bit map standards in line with jpeg2000 standards per 'Section F', perceptual quantization, and a full-fledged 'Jpeg2000' file in theory. Without which a potential theoretical test would, at base, potentially only receive a pass/fail completion.

A few assumptions: `s.buf' in C is an array of bytes. val does not exceed 8 bits.