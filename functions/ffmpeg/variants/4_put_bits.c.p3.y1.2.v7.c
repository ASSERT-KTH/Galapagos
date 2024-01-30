In Go, structs and methods are used instead of classes with methods that C provides. The equivalent implementation of the original C function in Go code is presented below:

go
type Jpeg2000EncoderContext struct {
	bitIndex uint8 
	buf      *[]byte 
}

func (s *Jpeg2000EncoderContext) putBits(val int, n int) { 
	for n > 0 {
		if s.bitIndex == 8{
			if (*s.buf)[0] == 0xff {
				s.bitIndex = 1
			} else {
				s.bitIndex = 0
			}
			*s.buf = append(*s.buf, 0)
		}
		(*s.buf)[len(*s.buf)-1] |= byte(val) << (7 - s.bitIndex)
		s.bitIndex++
		n--
	}
}


Note that unlike in C, you can range check slice i.e., using `len` function instead of avoiding buffer overflow. In Go the last byte is avaible in slice with `len(*s.buf)-1` instead of incrementing buf pointer. This Go code works best with Go coding principles in mind allowing for equivalent functionality to the C code but more safely due to intrinsic checks enforced by the Go runtime.