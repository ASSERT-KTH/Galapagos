Here is the Go translation of the given C code:

go
type Jpeg2000EncoderContext struct {
	buf       *[]byte
	bitIndex  int
}

func putBits(s *Jpeg2000EncoderContext, val int, n int) { // TODO: optimize
	for n > 0 {
		n--

		if s.bitIndex == 8 {
			s.bitIndex = 0
			if (*s.buf)[len(*s.buf)-1] == 0xff {
				s.bitIndex = 1
			}
			*s.buf = append(*s.buf, 0)
		}
		
		(*s.buf)[len(*s.buf)-1] |= byte(val << (7 - s.bitIndex))
		s.bitIndex++
	}
}


Please note that in Go zero values are different from null pointers and automatically initialized (and that slices are more common in use than array pointers). Therefore `*s->buf == 0xff` is currently checking if the last element in buffer is equal to `0xff`. The way in which `buf` was used and incremented in an expressive manner in C is usually not common in Go and could be prone to errors depending on how buffer was initialized, therefore, here the `buf` field in `Jpeg2000EncoderContext` type is modified to become a slice of byte. A new byte zero is then appended to end of buffer (simulating `(++s->buf) = 0` in original C function). Keep in mind that despite Go did complicate direct translation from C in this case its way dealed more smoothly with structs containing slices making allocating, reallocationg and element appending simpler compareted to C.