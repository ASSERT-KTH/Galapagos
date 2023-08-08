static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res;
    for (res = 0; n > 0; n--) {
        res *= 2;
        if (s->bit_index == 0) {
            s->bit_index = ((bytestream2_get_byte(&s->g) != 0xFFu) ? 8 : 7);  
        }
        res = res | ((bytestream2_peek_byte(&s->g) >> (s->bit_index - 1)) & 1);
        s->bit_index--;
    }
    return res;
}