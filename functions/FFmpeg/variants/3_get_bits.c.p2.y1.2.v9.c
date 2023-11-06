static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    int currentBitIndex;

    for (int i=n-1; i >= 0; i--) {
        res <<= 1;
        currentBitIndex = 7 + (bytestream2_get_byte(&s->g) != 0xFFu);

        if (s->bit_index == 0) {
            s->bit_index = currentBitIndex;
        }
        s->bit_index--;
        res |= ((bytestream2_peek_byte(&s->g) >> s->bit_index) & 1);
    }
    return res;
}