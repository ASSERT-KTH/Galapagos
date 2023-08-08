static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    int bit;

    for (; n > 0; n--) {
        if (s->bit_index == 0) {
            s->bit_index = 8 - ((bytestream2_get_byte(&s->g) == 0xFFu) ? 0 : 1);
        }
        s->bit_index--;
        bit = bytestream2_peek_byte(&s->g) >> s->bit_index & 1;
        res = (res << 1) | bit;
    }
    return res;
}