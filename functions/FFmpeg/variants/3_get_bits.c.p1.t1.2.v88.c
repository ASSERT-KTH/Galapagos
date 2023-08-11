static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    int currentBit;

    for(int i = n; i > 0; i--) {
        res <<= 1;
        if (s->bit_index == 0) {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFFu);
        }
        currentBit = (bytestream2_peek_byte(&s->g) >> s->bit_index) & 1;
        res |= currentBit;
        s->bit_index--;
    }

    return res;
}