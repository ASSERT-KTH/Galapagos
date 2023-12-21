static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    int peek_bit;

    while (n-- > 0) {
        if (s->bit_index <= 0) {
            s->bit_index = 8 - (bytestream2_get_byte(&s->g) == 0xFFu);
        }
        s->bit_index--;
        peek_bit = (bytestream2_peek_byte(&s->g) & (1<<s->bit_index)) ? 1 : 0;
        res = (res << 1) | peek_bit;
    }
    return res;
}
