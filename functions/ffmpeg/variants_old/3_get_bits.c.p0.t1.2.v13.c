static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    int m = n;

    while (--m >= 0) {
        if (s->bit_index == 0) {
            s->bit_index = ((bytestream2_get_byte(&s->g) != 0xFFu) ? 8 : 7);
        }
        res = (res << 1) | ((bytestream2_peek_byte(&s->g) >> (--s->bit_index)) & 1);
    }
    return res;
}