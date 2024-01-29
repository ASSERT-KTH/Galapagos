
func get_bits(s *Jpeg2000DecoderContext, n int) int {
    res := 0

    for n--; n >= 0; n-- {
        res <<= 1
        if s.bit_index == 0 {
            s.bit_index = 7 
            if bytestream2_get_byte(&s.g) != 0xFF {
               s.bit_index++
            }
        }
        s.bit_index--
        res |= (bytestream2_peek_byte(&s.g) >> uint(s.bit_index)) & 1
    }
    return res
}
