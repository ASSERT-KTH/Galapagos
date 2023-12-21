static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int result = 0;
    int bit;

    for (; n > 0; --n) {
        if (s->bit_index == 0) {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFF);
        }
        s->bit_index--;
        bit = (bytestream2_peek_byte(&s->g) >> s->bit_index) & 1;
        result = (result << 1) | bit;
    }
    return result;
}