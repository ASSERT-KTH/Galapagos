static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int result = 0;

    for(; n > 0; n--) {
        if (0 == s->bit_index) {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFFu);
        }
        result = (result << 1) | ((bytestream2_peek_byte(&s->g) >> (--s->bit_index)) & 1);
    }
    return result;
}