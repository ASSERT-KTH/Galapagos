static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int i, res = 0;
    for(i = n; i > 0; i--) {
        res <<= 1;
        if (s->bit_index == 0) {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFFu);
        }
        res |= (bytestream2_peek_byte(&s->g) >> --s->bit_index) & 0x01;
    }
    return res;
}