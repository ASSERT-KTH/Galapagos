static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;

    for (; n > 0; n--) {
        res *= 2;
        if (0 == s->bit_index) {
            s->bit_index = 7 + (0xFFu != bytestream2_get_byte(&s->g));
        }
        --s->bit_index;
        res |= (1 & (bytestream2_peek_byte(&s->g) >> s->bit_index));
    } 
    return res;
}