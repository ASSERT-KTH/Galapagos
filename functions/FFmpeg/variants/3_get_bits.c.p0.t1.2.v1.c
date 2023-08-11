static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    int temp;
    
    while (n-- > 0) {
        res = res << 1;
        if (s->bit_index == 0) {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 0 ? 1 : 0);
        }
        s->bit_index--;
        temp = bytestream2_peek_byte(&s->g) >> s->bit_index;
        res = res | (temp & 1);
    }
    return res;
}