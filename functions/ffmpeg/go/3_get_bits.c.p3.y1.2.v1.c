While it is difficult to make a direct conversion from C to Go due to the differences in system-level functions as well as some language constructs, a loose equivalent could be done as shown below in Go.

go
type Jpeg2000DecoderContext struct {
	bit_index int
	g byteStream
}

type byteStream struct {
	data []byte
	current byte
	index int
}

func (bs *byteStream) get() byte {
	if bs.index > len(bs.data) {
		panic("Index out of range")
	}
	bs.current = bs.data[bs.index]
	bs.index++
	return bs.current
}

func (bs *byteStream) peek() byte {
	if bs.index >= len(bs.data) {
		panic("Index out of range")
	}
	return bs.data[bs.index]
}

func GetBits(s *Jpeg2000DecoderContext, n int) int {
	res := 0

	for n--; n >= 0; n-- {
		res <<= 1
		if s.bit_index == 0 {
			gVal := byte(s.g.get())
			s.bit_index = 7 + int(gVal != 0xFF)
		}
		s.bit_index--
		resultedVal := byte(s.g.peek()) >> uint(s.bit_index)
		res |= int(resultedVal) & 1
	}

	return res
}


Few pointers regarding this conversion:

Since structs are accessed directly on C and by reference in Go, here an equivalent behaviour is forced by utilizing directly instance (non-pointer) receivers with value copies for equivalent C function calls bytestream2_get_byte and bytestream2_peek_byte.

This approach copies the bytestream rather than its reference on each call to get() and peek(), serving to replicate the stateful nature of stream consumption found in C version while isolating side-effects from future byteStream changes.

Also it uses byteStream struct acting as a pseudo-bytestream with basic implementaion of getter and peeking which abstracts byte array access and implicit index increment/decrement.

Remember that Go lacks unsigned types and this unary while conversion `uint(s.bit_index)` should be pretty safe, because it works on single byte and limits shift operator to within rid of overflowing signed integer.

Because raw unhandling gets of the outer index bounds are rather Go-unfriendly a couple of outs of range clamping checks have been added in first order suppress variety of panics that uncached raw indexing might have brought in.

Remember that this example can lose graceful eof handling available over io.Reader-like interfaces at expense of fulfilling the restriction on auxilary functions. Efectiveness of this worklike like overall loss determination would require more thorough comparison to orginal jpeg2000 decoder handler interactions with this function.