static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0, temp;

    while (n-- > 0) {
        res <<= 1;
        if (s->bit_index <=  0) {
            s->bit_index = 7 + (!(bytestream2_get_byte(&s->g) == 0xFFu));
        }
        s->bit_index--;
        temp = bytestream2_peek_byte(&s->g);
        res |= (temp >> s->bit_index) & 1;
    }
    return res;
}