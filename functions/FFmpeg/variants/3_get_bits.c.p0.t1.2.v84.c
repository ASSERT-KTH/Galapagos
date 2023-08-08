static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    int tmp = 0;
    int count = n;
   
    while (--count >= 0) {
        res <<= 1;
        if (s->bit_index == 0) {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) >= 0x100);
        }
        s->bit_index--;
        tmp = bytestream2_peek_byte(&s->g);
        tmp >>= s->bit_index;
        tmp &= 1;
        res |= tmp;
    }
    return res;
}