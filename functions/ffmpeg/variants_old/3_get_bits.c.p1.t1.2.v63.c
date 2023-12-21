static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    s->bit_index++;

    for (; n > 0; n--) {
        if (s->bit_index-- == 1) {
            s->bit_index = 8 - (bytestream2_get_byte(&s->g) != 255);
        }
        res = (res << 1) | ((bytestream2_peek_byte(&s->g) >> (s->bit_index - 1)) & 1);
    }
    return res;
}