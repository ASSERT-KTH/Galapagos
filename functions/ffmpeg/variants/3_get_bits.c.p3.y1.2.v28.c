Here is a Go equivalent of your C function. Please take into account that there is no difficulty doing this change as assumption needs to be made about what s->g or other called methods are doing. Please adjust accordingly to fit with your intended behaviour.

Go
type Jpeg2000DecoderContext struct {
	bit_index int32
	g         bytestream
}

type bytestream struct {
	index int32
	data  [whateverLength]int32
}

func (b *bytestream) get_byte() int32{
    // add getting byte logic here:
	// Use a around index to go and get from start when past end
	ret := b.data[b.index]
	b.index+
	b.index %= len(b.data)
	return ret
}

func (b *bytestream) peek_byte() int32{
	// just return data at index
	return b.data[b.index]
}


func getBits(s *Jpeg2000DecoderContext, n int32) int32 {
	res := int32(0)
	for n-=1; n >= 0; n-- {
		res <<= 1
		if s.bitIndex == 0 {
			s.bitIndex = 7 + (s.g.getByte() != 0xFF)
		}
		s.bitIndex--
		res |= (s.g.peek_byte() >> s.bitIndex) & 1
	}
	return res
}
