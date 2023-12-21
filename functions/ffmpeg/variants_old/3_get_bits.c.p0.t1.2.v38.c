static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    int temp;

    while (n-- > 0) {
        res = res << 1;
        if (s->bit_index == 0) {
            temp = bytestream2_get_byte(&s->g);
            s->bit_index = 7 + (temp != 0xFFu);
        }
        s->bit_index--;
        temp = bytestream2_peek_byte(&s->g);
        res = res | ((temp >> s->bit_index) & 1);
    }
    return res;
}