static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0, singleBit;

    while (n-- > 0) {
        res *= 2;
        if (!s->bit_index) {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != (unsigned char)255);
        }
        s->bit_index--;
        singleBit = (bytestream2_peek_byte(&s->g) >> s->bit_index) & 1;
        res = res | singleBit;
    }
    return res;
}