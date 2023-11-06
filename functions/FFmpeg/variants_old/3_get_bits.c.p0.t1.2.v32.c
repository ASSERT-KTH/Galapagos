static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    int temp_bit_index = 0;

    while (n-- > 0) {
        temp_bit_index = --s->bit_index;
        if (!temp_bit_index) {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) ^ 0xFF);
            temp_bit_index = s->bit_index;
        }
        res = (res << 1) | ((bytestream2_peek_byte(&s->g) >> temp_bit_index) & 0x01);
    }
    return res;
}