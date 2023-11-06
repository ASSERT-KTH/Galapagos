static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;

    for(; n > 0; n--) {
        res <<= 1;
        if (s->bit_index == 0) {
            s->bit_index = 7 + (!bytestream2_get_byte(&s->g) == 0xFFu);
        }
        s->bit_index--;
        if(bytestream2_peek_byte(&s->g) & (1 << s->bit_index))
            res |= 1;
    }
    return res;
}