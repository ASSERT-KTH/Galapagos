Here's the Go code that keeps the semantics equal, however, architecture of both languages is different, especially in Go without C-style pointers:

go
type Jpeg2000EncoderContext struct {
	buf       []byte
	bitIndex  int
	bufIndex  int
}

func putBits(s *Jpeg2000EncoderContext, val, n int) { 
	for n > 0 {
		if s.bitIndex == 8 {
			s.bitIndex = 0
			if s.buf[s.bufIndex] == 0xff {
				s.bitIndex = 1
			}
			s.bufIndex++
			s.buf = append(s.buf, 0)
		}
		s.buf[s.bufIndex] |= byte(val << (7 - s.bitIndex))
		s.bitIndex++
		n--
	}
}

Note: This might not replicate the exact same functionality due to the differences in language features of C and Go, especially you number `n` must be decreased inside the loop. In addition, it was necessary to add a bufIndex attribute to resolve pointer turning into increasing buffer issue with same mechanisms since Go language does not provide direct memory access as C does there are restrictions on pointers.
We are adding zero into the buffer slice and manipulating with our new "bufIndex" instead of changing next address byte value to 0 as you did "*s->buf = 0".