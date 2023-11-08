static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    for (; n > 0; n--) {
        res *= 2;
        if (s->bit_index == 0) {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFFu);
        }
        res |= (bytestream2_peek_byte(&s->g) >> --s->bit_index) & 1;
    }
    return res;
}