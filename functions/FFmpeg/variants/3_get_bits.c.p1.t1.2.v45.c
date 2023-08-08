static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0, idx = 0, temp = 0;

    for (idx = 0; idx < n; idx++) {
        if (!s->bit_index) {
            temp = bytestream2_get_byte(&s->g);
            s->bit_index = 8 - (temp == 0xFFu);
        }

        res <<= 1;
        res += ((bytestream2_peek_byte(&s->g) >> --s->bit_index) & 0x1);
    }

    return res;
}