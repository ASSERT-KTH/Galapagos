To have the equivalent function in Go, you need to slightly modify it cause Go is quite different in terms of syntax, and the memory management with java code:

go
type Jpeg2000DecoderContext struct { 
	bitIndex int
	g        *ByteStream
}

func GetBits(s *Jpeg2000DecoderContext, n int) int {
	res := 0

	for n = n-1; n >= 0; n-- {
		res <<= 1
		if s.bitIndex == 0 {
			s.bitIndex = 7 + BoolToInt(ByteStream.GetByte(s.g) != 0xFF)
		}
		s.bitIndex--
		res |= (ByteStream.PeekByte(s.g) >> s.bitIndex) & 1
	}
	return res
}

func BoolToInt(b bool) int {
	if b {
		return 1
	}
	return 0
}


In the given Go implementation, I defined a Jpeg2000DecoderContext struct where bitIndex represents the current bit index and *ByteStream abstractly represents the source of the bytes or data for this context. The conversion of get_bits function from C code to Go maintains the same algorithmic functionality. Handling booleans is a bit more involved in Go, as it is strongly-typed and explicit: I added a helper function, BoolToInt, to take care of that.

I should stress that this is just an attempt to match the functionality of the existing C code with crucial details unspecified - i.e., 'BitStream2_get_byte' and 'BitStream2_peek_byte' functions weren't defined in the provided C code, so in the mapping function, I suggestively replaced them with 'GetByte' and 'PeekByte' methods on the abstract ByteStream type, respectively. 

Included notation "(*)" on ByteStream pointing out that GetByte and PeekByte should be methods on ByteStream instance not on ByteStream pointer(s). It is always productive and advisable to fit any functionality to go idioms and practices.