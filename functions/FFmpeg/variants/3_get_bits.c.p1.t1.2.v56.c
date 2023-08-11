static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    int i;
    for(i = n; i > 0; i--) {
        res *= 2;
        if (s->bit_index == 0) {
            if(bytestream2_get_byte(&s->g) == 0xFFu)
                s->bit_index = 8;
            else
                s->bit_index = 7; 
        }
        res |= (bytestream2_peek_byte(&s->g) >> (s->bit_index - 1)) & 1;
        s->bit_index--;
    }
    return res;
}