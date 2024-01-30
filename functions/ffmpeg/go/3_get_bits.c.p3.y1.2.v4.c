In translation, I've kept the signature similar where 'Jpeg2000DecoderContext' is a structure that encapsulates context necessary for 'get_bits'. The variables represented by 's' will now be methods attached to this receiver. As Go doesn't support while loops with -- or ++ decrement called inside conditions, I transformed it into a for loop.

go
type Jpeg2000DecoderContext struct {
    bit_index int
    g         *ByteStream // Assume ByteStream structure
}

func (s *Jpeg2000DecoderContext) getBits(n int) int {
    res := 0

    for n--; n >= 0; n-- {
        res <<= 1
        if s.bit_index == 0 {
            if s.g.getByte() != 0xFF {
                s.bit_index = 8
            } else {         
                s.bit_index = 7
            }
        }
        s.bit_index--
        res |= (s.g.peekByte() >> s.bit_index) & 1
    }

    return res
}


In Go, `getByte` and `peekByte` are methods of `*ByteStream`. The ByteStream needs getter and peek methods in it. In Go, methods can be declared on struct pointer receivers like above.

However, you may also want to consider making extensive changes to the coding style and function signature if the entire project is written in Go. It's not recommended to purely mimic C's style while programming in Go. One of the motivations behind creating the Go language is to develop software with cleaner and more logical codes than C.