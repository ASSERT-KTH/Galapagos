Variant 1:

static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res, bits;
    
    res = 0;

    while(n-- > 0) 
    {
        res *= 2;
        
        if (s->bit_index == 0) 
        {
            s->bit_index = (bytestream2_get_byte(&s->g) != 255 ? 7 : 8);
        }

        --s->bit_index;
        
        bits = bytestream2_peek_byte(&s->g) >> s->bit_index;
        res |= bits & 1;    
    }
    
    return res;
}

Variant 2:

static int get_bits(Jpeg2000DecoderContext* s, int n)
{
    int res = 0, hasIndex0;

    do {
        res *= 2;
        hasIndex0 = s->bit_index == 0 ? 7 : s->bit_index;
        s->bit_index = hasIndex0 + (bytestream2_get_byte(&s->g) != 255u);
        s->bit_index -= 1;
        res += ((bytestream2_peek_byte(&s->g) >> s->bit_index) & 1);
    } while (--n >= 0);
  
    return res;
}

Variant 3:

static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    
    for( int i = n - 1; i >= 0; i--) 
    {
        res = res << 1;
        if(s->bit_index == 0) 
        {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFFu);
        }

        s->bit_index--;            
        res += ((bytestream2_peek_byte(&s->g) >> s->bit_index) & 1);    
    }

    return res;
}