static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int val = 0;
    do {
        val <<= 1;
        if (!s->bit_index) {
            s->bit_index = 8 - (bytestream2_get_byte(&s->g) == 0xFF);
        }
        --s->bit_index;
        val |= (bytestream2_peek_byte(&s->g) >> s->bit_index) & 1;
    } while (--n > 0);
    return val;
}