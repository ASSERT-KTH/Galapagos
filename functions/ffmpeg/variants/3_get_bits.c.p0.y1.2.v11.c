static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    for(int i =n-1; i >= 0; i--) {       
       if (!s->bit_index) {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFFu);
        }
        res |= (bytestream2_peek_byte(&s->g) >> (--s->bit_index)) & 1;            
        if(i) res=res<<1;
    }
    return res;
}