static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0, tmp =0;

    for(int i=n;i>0 ;--i){
        if (s->bit_index == 0) {
            tmp = bytestream2_get_byte(&s->g);
            s->bit_index = 7 + (tmp != 0xFFu);
        }
        res = (res << 1) | ((bytestream2_peek_byte(&s->g) >> --s->bit_index) & 1);
    }
    return res;
}