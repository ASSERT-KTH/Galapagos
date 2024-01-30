In Go language, you cannot use the '->' symbol for manipulation of struct's field like in C. You have to use the '.' (dot notation). Also ensure you initialise variable fields of the mock 'Jpeg2000EncoderContext' struct object. 

Here is your semantically equivalent code in Go: 

go
type Jpeg2000EncoderContext struct {
	buf       *[]byte
	bit_index int
}

func put_bits(s *Jpeg2000EncoderContext, val int, n int) {
	for n > 0 {
		n--
		if s.bit_index == 8 {
			if (*s.buf)[0] == 0xff {
				s.bit_index = 1
			} else {
				s.bit_index = 0
			}
			*s.buf = append(*(s.buf), 0)
		}
		(*s.buf)[len(*s.buf)-1] |= byte(val) << uint(7-s.bit_index)
		s.bit_index++
	}
}


Kindly implement 'Jpeg2000EncoderContext' struct by your own needs,this above is my presumption. For 'buf' in Go, we're using a slice of bytes, because slices are the required cause in terms of capability and size in Go language, with top factor referencing ' pointer to slices is the effective way of dealing with data structures such as a list of elements'.