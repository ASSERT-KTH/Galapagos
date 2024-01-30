static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    int bitValue = 0;

    while (n-- > 0) {
        bitValue = bytestream2_peek_byte(&s->g) >> (s->bit_index -1) & 1; 

        if (s->bit_index == 0) {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFFu);
        }

        res = (res << 1) | bitValue;

        --s->bit_index;
    }

    return res;
}