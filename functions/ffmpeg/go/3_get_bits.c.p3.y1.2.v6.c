go
type Jpeg2000DecoderContext struct {
	bitIndex int
	g        *ByteStream
}

type ByteStream struct {
	bytes []byte
}

func (b *ByteStream) getByte() uint8 {
	byt := b.bytes[0]
	b.bytes = b.bytes[1:]
	return byt
}

func (b *ByteStream) peekByte() uint8 {
	return b.bytes[0]
}

func getBits(s *Jpeg2000DecoderContext, n int) int {
	res := 0
	for n -= 1; n >= 0; 	n -= 1  {
		res <<= 1
		if s.bitIndex == 0 {
			if s.g.getByte() != 0xFF {
				s.bitIndex = 7
			} else {
				s.bitIndex = 8
			}
		}
		s.bitIndex -= 1
		res |= int(s.g.peekByte()>>uint(s.bitIndex)) & 1
	}
	return res
}
