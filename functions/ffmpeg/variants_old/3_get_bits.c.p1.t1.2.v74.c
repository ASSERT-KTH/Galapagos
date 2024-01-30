static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    int diff;

    for (; n > 0; n--) {
        res <<= 1;
        if (0 == s->bit_index) {
            diff = bytestream2_get_byte(&s->g) == 0xFFu ? 8 : 7;
            s->bit_index = diff;
        }
        s->bit_index--;
        diff = (bytestream2_peek_byte(&s->g) >> s->bit_index) & 1;
        res |= diff;
    }
    return res;
}