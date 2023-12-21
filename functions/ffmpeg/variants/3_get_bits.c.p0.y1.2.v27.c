static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int bit_sum = 0;

    for (; n > 0; --n) {
        bit_sum <<= 1;

        if (s->bit_index == 0) {
            s->bit_index = 8 - (bytestream2_get_byte(&s->g) == 0xFFu);
        }

        bit_sum |= ((bytestream2_peek_byte(&s->g) >> --s->bit_index) & 1);
    } 

    return bit_sum;
}