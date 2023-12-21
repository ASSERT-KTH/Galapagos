static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    unsigned byte = 0;

    while (n-- > 0) {
        res *= 2;
        if (s->bit_index == 0) {
            byte = bytestream2_get_byte(&s->g);
            s->bit_index = (!byte) ? 7 : 8;
        }
        s->bit_index--;
        res |= (bytestream2_peek_byte(&s->g) & (1 << s->bit_index)) != 0;
    }
    return res;
}