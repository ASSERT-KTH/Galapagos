Your request is quite challenging. First, Go lacks direct access to memory through pointers. Second, C language structure in Go would have to be converted to a struct. Finally, error handling differs between Go and C quite bit.

Try this conservative implementation:

go
type Jpeg2000EncoderContext struct {
	buf       *[]byte
	bit_index byte
}

func put_bits(s *Jpeg2000EncoderContext, val int, n int) { // TODO: optimize
	for n > 0 {
		n--
		if s.bit_index == 8 {
			s .bit_index = 0
			if (*s.buf)[0] == 0xff {
				s.bit_index = 1
			}
			*s.buf = append(*s.buf, 0)
		}
		
		(*s.buf)[len(*s.buf)-1] |= byte(val) << (7 - s.bit_index)
		s.bit_index++
	}
}


Assuming that above "s->buf == 0xff" implementation in the original C code refers to comparison with the last byte of buf (equivalent to adding zero at the end when unnecessary).

Can you please provide additional information about "s->buf == 0xff" part? If you has a different intent, the Go implementation may need to be changed. Please clarify.