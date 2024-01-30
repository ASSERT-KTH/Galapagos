static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0, idx_val;

    while (n-- > 0) {
        res *= 2;
        if (!(s->bit_index)) {
            idx_val = 7 + (bytestream2_get_byte(&s->g) != 0xFFu);
            s->bit_index = idx_val;
        }
        s->bit_index--;
        res |= (bytestream2_peek_byte(&s->g) >> s->bit_index) & 1;
    }
    return res;
}