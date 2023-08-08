static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    unsigned char tmp;

    for(; n > 0; n--){
        res <<= 1;
        if (!s->bit_index)
        {
            tmp = bytestream2_get_byte(&s->g);
            s->bit_index = (tmp != 0xFFu) ? 8 : 7;
        }
        s->bit_index--;
        tmp = bytestream2_peek_byte(&s->g);
        res |= (tmp >> s->bit_index) & 1;
    }
    return res;
}