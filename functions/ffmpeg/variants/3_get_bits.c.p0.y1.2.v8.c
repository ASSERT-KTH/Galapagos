static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0, value;

    while (n-- > 0) {
        res *= 2;
        if (s->bit_index == 0) {
            value = bytestream2_get_byte(&s->g);
            s->bit_index = 8 - (value == 0xFFu);
        }
        s->bit_index--;
        res = res | ((bytestream2_peek_byte(&s->g) >> s->bit_index) & 1);
    }
    return res;
}