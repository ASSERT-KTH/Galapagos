static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    int value, is_not_FF;

    while (n-- > 0) {
        res <<= 1;

        if (s->bit_index == 0) {
            value = bytestream2_get_byte(&s->g);
            is_not_FF = value != 0xFFu;
            s->bit_index = 7 + is_not_FF;
        }
        s->bit_index--;
        
        value = bytestream2_peek_byte(&s->g);
        res |= (value >> s->bit_index) & 1;
    }

    return res;
}
