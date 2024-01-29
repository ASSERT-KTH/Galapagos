Unfortunately, a straight-forward equivalent implementation is not possible due to some key differences between C and Go languages. The "Jpeg2000DecoderContext" struct and "bytestream2_get_byte" & "bytestream2_peek_byte" functions are unique to your application written in C, you need to find the equivalents in Go or rewrite them.

One attempt of conversion might look like:

Go
type Jpeg2000DecoderContext struct {
	g         AnyTypeYouNeedToDecide
	bit_index int    
}

func get_bits(s *Jpeg2000DecoderContext, n int) int {
	res := 0

	for n--; n >= 0; n-- {
		res <<= 1
		if s.bit_index == 0 {
			s.bit_index = 7 + byte(bytestream2_get_byte(&s.g) != 0xFF)
		}
		s.bit_index--
		res |= (bytestream2_peek_byte(&s.g) >> s.bit_index) & 1
	}
	return res
}


In the above Go code draft, "AnyTypeYouNeedToDecide" needs to be replaced with pertinent Go suitable datatype. 

Again please note, it's not an exact translation, as Go Language has intrinsic characteristics and practices which include different Error Handling implementations, good routines, different library for handling bytes. 

Therefore, we might need to see the `bytestream2_*` function to have clear idea. For the purpose of security and correctness, if your software needs porting to Go, its  considerable to have professional assistance.