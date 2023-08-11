static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    int bit = 0;
    while (n-- > 0) {
        bit = bytestream2_peek_byte(&s->g) >> s->bit_index & 0x01;
        res = (res << 1) | bit;
        if (s->bit_index == 0) {
            s->bit_index = (bytestream2_get_byte(&s->g) != 0xFF) ? 8 : 7;
        }
        s->bit_index--;
    }
    return res;
}