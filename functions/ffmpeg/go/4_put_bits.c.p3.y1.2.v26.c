Here's how you can implement the same function in Go:

go
type Jpeg2000EncoderContext struct {
	bitIndex int
	buf      *[]byte
}

func putBits(s *Jpeg2000EncoderContext, val int, n int) { // TODO: optimize
	for n > 0 {
		n--
		if s.bitIndex == 8 {
			s.bitIndex = 0
			if (*s.buf)[0] == 0xff {
				s.bitIndex = 1
			}
			*s.buf = append(*s.buf, 0)
		}
		(*s.buf)[len(*s.buf)-1] |= byte(val << (7 - s.bitIndex))
		s.bitIndex++
	}
}

Please note that in this Go code, to preserve all pointer arragements from the original C code, I've represented the dynamic/pointer-based character of variable `bu?` from the original code by encapsulating it in a slice. This is necessary to cover all eventual usages of the concept of pointer of original C code in Go, which primarily works with slices instead of generic poinAddress manipulation. Please adapt according to your specific use case and careful about memory consumption (as slices differ from pointers in the manner of heap memory allocation).