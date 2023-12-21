static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0, offset = 0;

    while (n-- > 0) {
        if (s->bit_index == 0) {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFFu);
        } else {
            s->bit_index--;
        }

        offset = (bytestream2_peek_byte(&s->g) >> s->bit_index) & 1;
        res = (res << 1) | offset;
    }

    return res;
}