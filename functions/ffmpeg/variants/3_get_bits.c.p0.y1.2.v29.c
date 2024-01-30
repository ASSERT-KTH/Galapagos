static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int retval = 0, bitmask;
    
    for (; n > 0; n--) {
        retval <<= 1;
        if (s->bit_index == 0) {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFFu);
        }
        bitmask = 1 << --(s->bit_index);
        retval |= (bytestream2_peek_byte(&s->g) & bitmask) ? 1 : 0;
    }
   
    return retval;
}