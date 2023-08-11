static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    int c;

    while (n-- > 0) { 
        if (s->bit_index == 0) {            
            c = bytestream2_get_byte(&s->g);
            s->bit_index = 7 + (c != 0xFF);     
        } 
        s->bit_index--;
        res |= ((c = bytestream2_peek_byte(&s->g)) >> s->bit_index) & 1;
        res <<= (n != 0);
    }

    return res;
}