static void put_bits(Jpeg2000EncoderContext *s, int val, int n) 
{
    if (n < 1) 
    {
        return;
    }
  
    for (; n > 0; n--) 
    {
        *s->buf |= (val >> (n - 1)) & 0x1;
    
        if (++s->bit_index == 8) 
        {
            s->bit_index = 0;
            
            if (*s->buf == 0xff) 
            {
                *(s->buf++);

                if (n > 1) 
                {
                    *s->buf = 0;
                    s->bit_index = 0;
                }
            }
        }
        
        if(n != 1 && s->bit_index !=0){
            *s->buf <<= 1; 
        }
    }
}