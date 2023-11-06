static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    int bit_index;
    int peeked_byte;

    for (; n > 0; n--) {
        res <<= 1;
        bit_index = s->bit_index;
        if (bit_index == 0) {
            bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFFu);
        }
        s->bit_index = bit_index - 1;
        peeked_byte = bytestream2_peek_byte(&s->g);
        res |= (peeked_byte >> s->bit_index) & 1;
    }
    return res;
}