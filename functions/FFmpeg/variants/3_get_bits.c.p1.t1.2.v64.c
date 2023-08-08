static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    int loc_index;

    while (n-- > 0) {
        res <<= 1;
        loc_index = s->bit_index == 0;

        if (loc_index) {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFFu);
        }
        s->bit_index--;
        res |= (bytestream2_peek_byte(&s->g) >> s->bit_index) & 1;
    }
    return res;
}