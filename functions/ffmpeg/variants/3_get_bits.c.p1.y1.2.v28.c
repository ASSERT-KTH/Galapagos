static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    n = n - 1;
    do
    {
        res = res << 1;
        if (s->bit_index == 0)
        {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFFu);
        }

        s->bit_index = s->bit_index - 1;

        unsigned int res_new = (bytestream2_peek_byte(&s->g) >> s->bit_index) & 1;
        res = res | res_new;
        
        n--;
    } while(n >= 0);
    
    return res;
} 

--------------------

static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    int term_condition = 0;

    while (--n >= term_condition)
    {
        res = (res << 1);
        
        int zero_condition = 0;
        
        if (s->bit_index == zero_condition)
        {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != (unsigned int)0xFF);
        }

        s->bit_index -= 1;

        res |= ((bytestream2_peek_byte(&s->g) >> s->bit_index) & 1);
    }
  
    return res;
}

----------------------------

static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int shifted;
    int res = 0;

    while (--n >= 0) 
    {
        res <<= 1;
        
        if (s->bit_index == 0) 
        {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFF);
        }

        s->bit_index--;

        shifted = bytestream2_peek_byte(&s->g) >> s->bit_index;
        res = res | (shifted & 1);
    }

    return res;
}