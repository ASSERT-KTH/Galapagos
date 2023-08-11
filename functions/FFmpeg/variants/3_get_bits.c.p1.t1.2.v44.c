static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0, updated_bit_index, next_bit;

    for (int count = n; count > 0; count--) {
        res = res << 1;

        if (s->bit_index == 0) {
            updated_bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFFu);
            s->bit_index = updated_bit_index != 0 ? updated_bit_index : s->bit_index;
        }

        next_bit = bytestream2_peek_byte(&s->g) >> s->bit_index;
        res |= (next_bit & 1);
        s->bit_index--;
    }

    return res;
}