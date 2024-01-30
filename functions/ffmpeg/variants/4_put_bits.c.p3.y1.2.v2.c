The semantic equivalent of the above function in Go language would look something like this:

go
func putBits(s *Jpeg2000EncoderContext, val int, n int) {
	for n--; n >= 0; n-- {
		if s.bitIndex == 8 {
			if *s.buf == '\xff' {
				s.bitIndex = 1
			} else {
				s.bitIndex = 0
			}
			s.buf++
			*s.buf = 0
		}
		*s.buf |= byte(val << (7 - s.bitIndex))
		s.bitIndex++
	}
}


Please, note that in Go language `->` is replaced with `.`
Also, in Go individual bytes are typically manipulated as values of type byte. `byte` is an alias for `uint8` and is equivalent to `uint8` in all ways. It is used, by convention, to distinguish byte values from 8-bit unsigned integer values. In this case, `*s->buf` replaced with 'byte(*s.buf)'.