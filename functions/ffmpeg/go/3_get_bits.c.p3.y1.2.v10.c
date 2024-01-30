golang
type Jpeg2000DecoderContext struct {
	BitIndex int
	G        *ByteStream
}

func (s *Jpeg2000DecoderContext) getBits(n int) int {
	res := 0

	for n--; n >= 0; n-- {
		res <<= 1
		if s.BitIndex == 0 {
			if s.G.getByte() != 0xFF {
				s.BitIndex = 8
			} else {
				s.BitIndex = 7
			}
		}
		s.BitIndex--
		res |= (s.G.peekByte() >> uint(s.BitIndex)) & 1
	}
	return res
}

type ByteStream struct {
	// underlying slice and index
	Data []byte
	Pos  int
}

// read and also forward index position 
func (b *ByteStream) getByte() byte {
	val := b.Data[b.Pos]
	b.Pos++
	return val
}

// read but do not forward position
func (b *ByteStream) peekByte() byte {
	return b.Data[b.Pos]
}
