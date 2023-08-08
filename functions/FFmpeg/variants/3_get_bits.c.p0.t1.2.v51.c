static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0, temp_bit;

    for (; n > 0; n--) {
        res <<= 1;
        temp_bit = bytestream2_get_byte(&s->g);
        if (s->bit_index == 0) {
            s->bit_index = temp_bit != 0xFFu ? 8 : 7;
        }
        if ((temp_bit >> --s->bit_index) & 1)
            res |= 1;
    }

    return res;
}