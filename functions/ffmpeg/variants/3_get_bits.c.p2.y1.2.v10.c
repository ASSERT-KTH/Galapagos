static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0, byestr;
    for (; n > 0; --n){
        res <<= 1;
        if (s->bit_index == 0) {
            byestr = (bytestream2_get_byte(&s->g) != 0xFFu);
            s->bit_index = byestr ? 8 : 7;
        }
        s->bit_index--;
        res |= (bytestream2_peek_byte(&s->g) >> s->bit_index) & 1;
    }
    return res;
}