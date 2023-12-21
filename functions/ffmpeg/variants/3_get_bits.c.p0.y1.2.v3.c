static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int result = 0;
    int count = n;

    for (; count > 0; count--) {
        result = result << 1;
        if (!s->bit_index) {
            s->bit_index = 7 + ((bytestream2_get_byte(&s->g) != 0xFFu) ? 1 : 0);
        }
        s->bit_index--;
        result |= ((bytestream2_peek_byte(&s->g) >> s->bit_index) & 1);
    }
    return result;
}