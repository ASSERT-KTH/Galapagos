static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int result = 0;

    do {
        result <<= 1;
        if (!s->bit_index) {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) > 0xFE ? 1 : 0);
        }
        --s->bit_index;
        result |= (bytestream2_peek_byte(&s->g) >> s->bit_index) & 1;
    } while (--n > 0);

    return result;
}