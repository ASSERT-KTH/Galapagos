static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    int tmp = 0;

    while (n-- > 0) {
        if (s->bit_index == 0) {
            s->bit_index = 8 - !bytestream2_get_byte(&s->g);
        }
        --s->bit_index;
        tmp = (bytestream2_peek_byte(&s->g) & (1 << s->bit_index));
        res = (res << 1) | (tmp != 0);
    }
    
    return res;
}
