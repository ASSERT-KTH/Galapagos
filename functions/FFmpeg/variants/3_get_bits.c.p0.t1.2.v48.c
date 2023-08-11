static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    int update_index;

    while (n-- > 0) {
        res <<= 1;
        update_index = 7;
        if (s->bit_index != 0) {
            update_index += (bytestream2_get_byte(&s->g) == 0xFFu) ? 0 : 1;
        }
        s->bit_index = update_index;
        s->bit_index--;
        res |= (bytestream2_peek_byte(&s->g) >> s->bit_index) & 1;
    }
    return res;
}