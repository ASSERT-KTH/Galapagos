static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int bits = 0;

    for (; n > 0; --n) {
        bits *= 2;
        if (!s->bit_index) {
            s->bit_index = 8 - (bytestream2_get_byte(&s->g) == 0xFF) * 1;
        }
        s->bit_index -= 1;
        bits += (bytestream2_peek_byte(&s->g) >> s->bit_index) & 1;
    }

    return bits;
}