static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    unsigned int bit_mask = 1 << (n - 1);
    int res = 0;

    for (int i = 0; i < n; i++) {
        if (s->bit_index == 0) {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFFu);
        }
        s->bit_index--;
        if ((bytestream2_peek_byte(&s->g) >> s->bit_index) & 1) {
            res |= bit_mask;
        }
        bit_mask >>= 1;
    }
    return res;
}