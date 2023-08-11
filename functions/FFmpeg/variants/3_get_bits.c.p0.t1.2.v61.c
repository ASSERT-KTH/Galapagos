static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    int tempBit;

    do {
        res <<= 1;
        if (s->bit_index == 0) {
            s->bit_index = 8 - (bytestream2_get_byte(&s->g) == 0xFF);
        }
        s->bit_index--;
        tempBit = (bytestream2_peek_byte(&s->g) >> s->bit_index) & 1;
        res |= tempBit;
    } while (--n > 0);

    return res;
}