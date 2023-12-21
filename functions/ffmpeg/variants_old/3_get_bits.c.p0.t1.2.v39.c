static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    int tempBitIndex;

    while (--n >= 0) {
        res <<= 1;
        tempBitIndex = s->bit_index;
        
        if (tempBitIndex == 0) {
            tempBitIndex = 7 + (bytestream2_get_byte(&s->g) != 0xFFu);
        }

        tempBitIndex--;
        
        res |= (bytestream2_peek_byte(&s->g) >> tempBitIndex) & 1;
        s->bit_index = tempBitIndex;
    }

    return res;
}