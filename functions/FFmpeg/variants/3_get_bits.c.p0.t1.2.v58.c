static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;

    while(n-- > 0) {
        res = (res << 1);
        if (s->bit_index == 0) {
            s->bit_index = 7 + ((bytestream2_get_byte(&s->g) == 0xFFu) ? 0 : 1);
        }

        s->bit_index--;
        res |= ((bytestream2_peek_byte(&s->g) >> s->bit_index) & 1);
        s->bit_index &= 7;
    }

    return res;
}