static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    int bit;

    while (n-- > 0) {
        res = (res << 1);
        if (s->bit_index <= 0) {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) > 0xFE);
            s->bit_index--;
        }
        else {
            s->bit_index--;
        }
        bit = bytestream2_peek_byte(&s->g);
        res |= ((bit >> s->bit_index) & 1);
    }
    return res;
}