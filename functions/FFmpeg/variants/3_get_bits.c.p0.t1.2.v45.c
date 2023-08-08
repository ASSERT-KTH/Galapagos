static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    int temp_bit_index_comparator = 7;

    do {
        res = res << 1;
        if (s->bit_index == 0) {
            s->bit_index = temp_bit_index_comparator + bytestream2_get_byte(&s->g) != 0xFFu;
        }
        s->bit_index = s->bit_index - 1;
        res |= (bytestream2_peek_byte(&s->g) >> s->bit_index) & 1;
    } while (--n > 0);

    return res;
}