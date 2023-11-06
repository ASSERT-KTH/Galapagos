Here is a semantically equivalent Go function:
go
type Jpeg2000EncoderContext struct {
	buf       *[]byte
	bit_index int
}

func put_bits(s *Jpeg2000EncoderContext, val int, n int) {
	for n > 0 {
		if s.bit_index == 8 {
			s.bit_index = 0
			if (*s.buf)[0] == 0xff {
				s.bit_index = 1
			}
			*s.buf = append(*s.buf, 0)
		}
		(*s.buf)[len(*s.buf)-1] |= byte(val << (7 - s.bit_index))
		s.bit_index++
		n--
	}
}

This function writes bits into a buffer in the `Jpeg2000EncoderContext` object `s`.

(Please note that the equivalent behavior might be not 100% similar due to the different ways how those two programming languages (C and Go) handle pointers and arrays so additional checking or specific errors handling may be necessary).