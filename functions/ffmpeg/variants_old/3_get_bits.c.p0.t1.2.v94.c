static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    unsigned int result = 0;
    int decrease_n = n;

    while (--decrease_n >= 0) {
        result = result << 1;
        if (s->bit_index == 0) {
            if (bytestream2_get_byte(&s->g) != 255) {
                s->bit_index = 8;
            } else {
                s->bit_index = 7;
            }
        }
        s->bit_index--;
        result |= (bytestream2_peek_byte(&s->g) >> s->bit_index) & 1;
    }
    return result;
}