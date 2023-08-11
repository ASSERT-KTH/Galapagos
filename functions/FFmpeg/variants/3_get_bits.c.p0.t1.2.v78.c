static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    int decrease_value = 1;
    s->bit_index = (s->bit_index == 0) ? 7 + (bytestream2_get_byte(&s->g) != 0xFFu) : s->bit_index;

    while (n-- > 0) {
        bool byte_value;
        s->bit_index -= decrease_value;
        byte_value = (bytestream2_peek_byte(&s->g) >> s->bit_index) & 1;
        res <<= 1;
        res |= byte_value;
        if (n < 0) break;

        if (s->bit_index == 0) {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFFu);
        } 
    }
    return res;

}