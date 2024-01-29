Unfortunately, exactly translating C code into Go isn't possible due to some fundamental differences between two programming languages. These differences include refinements in data types, pointer handling paradigms and memory level control.

However, if we consider the general context, hypotheses and over-simplifications about the original C code operation and data structures, the Go code for the equivalent behavior could be something similar as below, in pseudo code:

go
type Jpeg2000EncoderContext struct {
	buf       *[]byte
	bit_index int
}

func putBits(s *Jpeg2000EncoderContext, val int, n int) {
	for n > 0 {
		n--
		if s.bit_index == 8 {
			s.bit_index = 0
			if (*s.buf)[s.bit_index] == 0xff {
				s.bit_index = 1
			} else {
				s.bit_index = 0
			}
			s.buf = &([]byte{0})
		}
		(*s.buf)[s.bit_index] |= byte(val << (7 - s.bit_index))
		s.bit_index++
	}
}

While this code is in theory similar, there were assumptions made about the implementation of your the Jpeg2000EncoderContext struct and its properties, so it might warrant further modifications to fit into the larger design paradigm you might be working on in Go. The biggest difference is how Go handles lower level memory and pointers compared to C. It's important, you do testing as per real application requirement after writing Go code from C.

I hope this code can give you a baseline or a direction to start with.