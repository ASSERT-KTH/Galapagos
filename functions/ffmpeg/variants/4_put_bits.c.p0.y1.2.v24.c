static void put_bits(Jpeg2000EncoderContext *s, int val, int n)
{
    for(int i=n-1; i>=0; i--)
    {
        int current_bit = val >> i & 1;  
 
        if (s->bit_index == 8)    
        {
            s->bit_index = *s->buf == 0xff ? 1 : 0;  
            *(++s->buf) = 0; 
        }
 
        *s->buf |= current_bit << (7 - (s->bit_index++)); 
    }
}