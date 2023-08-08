static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    int cur_bit = 0;
    for (; n > 0; n--) {
        if (!s->bit_index) {
            if (bytestream2_get_byte(&s->g) != 0xFFu) {
                s->bit_index = 8;
            } else {
                s->bit_index = 7;
            }
        }

        cur_bit = (bytestream2_peek_byte(&s->g) >> (s->bit_index - 1)) & 1;
        res = (res << 1) | cur_bit;
        s->bit_index--;
    }
    return res;
}