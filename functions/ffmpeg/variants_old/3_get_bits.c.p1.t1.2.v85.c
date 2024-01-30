static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0, bit_value = 0;

    for (int i = n - 1; i >= 0; i--) {
        if (s->bit_index <= 0) {
            bit_value = (bytestream2_get_byte(&s->g) != 0xFFu) ? 7 : 6;
            s->bit_index = bit_value;
        }
        res |= ((bytestream2_peek_byte(&s->g) >> (--s->bit_index)) & 1) << i;
    }

    return res;
}