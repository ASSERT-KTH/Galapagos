Here is the Go translation of the function:

Go
type Jpeg2000EncoderContext struct {
	buf       *[]byte
	bit_index int
}


func put_bits(s *Jpeg2000EncoderContext, val int, n int)  { // TODO: optimize

	for n > 0 {
		n--
		if s.bit_index == 8 {
			s.bit_index = 0
			if (*s.buf)[0] == 0xff { 
				s.bit_index = 1
			}		

			*s.buf = append(*s.buf, 0) 
			copy((*s.buf)[1:], (*s.buf)[:])
			(*s.buf)[0] = 0
		}
		(*s.buf)[0] |= byte(val << (7 - s.bit_index))
		s.bit_index++
    }
}


PS. Please note that Go doesn't do pointer arithmetic the same way C does, so changes have been made.