static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0, one_base = 1;

    for(int i = 0; i < n; i++) {
        if (s->bit_index == 0) 
        {       
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFFu);      
        }
        s->bit_index--;
        res |= ((bytestream2_peek_byte(&s->g) >> s->bit_index) & one_base) << (n - 1 - i);           
    }
    return res;
}