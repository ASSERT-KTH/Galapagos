In Go, the semantically equivalent version of the function might be:

golang
func get_bits(s *Jpeg2000DecoderContext, n int) int {
    res := 0
    for n--; n >= 0; n-- {
        res <<= 1
        if s.bit_index == 0 {
            s.bit_index = 7 + byte(bytestream2_get_byte(&s.g)^0xFF)
        }
        s.bit_index--
        res |= int(bytestream2_peek_byte(&s.g) >> s.bit_index) & 1
    }
    return res
}

Please note that `bytestream2_get_byte` and `bytestream2_peek_byte` are required to be implemented or available in the Go package context. The real might differ based on your exact use context, like the bit manipulation operation, or error/exception handling, etc. The same rule applies to `Jpeg2000DecoderContext` struct which should be having `bit_index` and `g` type-defined according to C counterpart.

Implementations of `bytestream2_get_byte` and `bytestream2_peek_byte` might be looking something like this:-

golang
func bytestream2_get_byte(g *bytestream2) byte {
// Your implementation to get a byte.
}

func bytestream2_peek_byte(g *bytestream2) byte {
// Your implementation to peek a byte.
}
