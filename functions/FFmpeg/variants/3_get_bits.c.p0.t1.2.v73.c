static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    unsigned int res = 0;
    unsigned char currentValue;

    for (int i = n; i > 0; --i) {
        if (s->bit_index == 0) {
            currentValue = bytestream2_get_byte(&s->g);
            s->bit_index = 7 + (currentValue != 0xFF);
        }
        --s->bit_index;
        res = (res << 1) | ((bytestream2_peek_byte(&s->g) >> s->bit_index) & 1);
    }
    return (int) res;
}