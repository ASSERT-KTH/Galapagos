static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    int bit_index = s->bit_index, shifted_peek_byte;
    unsigned int peek_byte;

    for (; n > 0; n--) {
        res <<= 1;
        if (bit_index == 0) {
            bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFFu); 
        }
        bit_index--;
        peek_byte = bytestream2_peek_byte(&s->g);
        shifted_peek_byte = (peek_byte >> bit_index) & 1;
        res |= shifted_peek_byte;
    }
    s->bit_index = bit_index;

    return res;
}