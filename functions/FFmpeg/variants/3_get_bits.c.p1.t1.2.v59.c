static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0, tmp, offset;

    for(int i = n-1; i >= 0; i--){
        if (s->bit_index == 0) {
            tmp = bytestream2_get_byte(&s->g);
            s->bit_index = 8 - (tmp == 0xFFu);
        }
        offset = --s->bit_index;
        temp = bytestream2_peek_byte(&s->g);
        res |= ((temp >> offset) & 1) << i;
    }
    return res;
}