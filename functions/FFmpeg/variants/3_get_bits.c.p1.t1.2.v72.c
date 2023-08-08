static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    for (int i = n; i > 0; i--) {
        res = res << 1;
        if (!s->bit_index) {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFFu);
        }
        s->bit_index--;
        int tmp = bytestream2_peek_byte(&s->g);
        res = res | ((tmp >> s->bit_index) & 1);
    }
    return res;
}