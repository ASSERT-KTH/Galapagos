Here are 4 variations of the original function preserving its functionality while changing its structure slightly:

Option 1:


static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    for (int i = n; i > 0; i--){
        res <<= 1;
        if (0 == s->bit_index) {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFFu);
        }
        res |= (bytestream2_peek_byte(&s->g) >> --s->bit_index) & 1;
    }     
    return res;
}

Option 2:


static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    do {
        res <<= 1;
        if(s->bit_index == 0) 
            s->bit_index = 7 + (!(bytestream2_get_byte(&s->g) == 0xFFu));
        res |= (bytestream2_peek_byte(&s->g) >> --s->bit_index) & 1;
    } while (--n > 0);
    return res;
}

Option 3:


static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0, i = n;
    while (i-- > 0) {
        res = (res << 1) | ((s->bit_index != 0) ? ((bytestream2_peek_byte(&s->g) >> --s->bit_index)&1)
                                                 : ((s->bit_index = 7 + !bytestream2_get_byte(&s->g) == 0xFFu)));
    }
    return res;
}

Option 4:


static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    
    while(n-- > 0) 
    {
        res = res << 1;
        
        if(s->bit_index == 0)
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFF);
            
        s->bit_index--;

        int data = bytestream2_peek_byte(&s->g);
        res = res | (( data >> s->bit_index) & 1); 
    }
     
    return res;
}
