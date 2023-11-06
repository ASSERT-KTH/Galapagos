static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int result = 0;
    for (int i = n; i > 0; --i) {
        result = result * 2;
        if (s->bit_index == 0) {
            if (bytestream2_get_byte(&s->g) != 0xFFu) {
                s->bit_index = 8;
            } else {
                s->bit_index = 7;
            }
        }
        result += (bytestream2_peek_byte(&s->g) >> --s->bit_index) & 1;
    }
    return result;
}