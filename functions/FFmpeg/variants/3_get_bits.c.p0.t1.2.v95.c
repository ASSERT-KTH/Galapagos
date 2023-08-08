static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    unsigned int res = 0;
    int shiftCount = 0;

    while (n > 0) {
        res <<= 1;
        --n;
        if (s->bit_index == 0) {
            s->bit_index = (bytestream2_get_byte(&s->g) == 0xFFu) ? 8 : 7;
        }
        s->bit_index--;
        shiftCount = s->bit_index;
        res |= (bytestream2_peek_byte(&s->g) >> shiftCount) & 1;
    }
    return (int)res;
}