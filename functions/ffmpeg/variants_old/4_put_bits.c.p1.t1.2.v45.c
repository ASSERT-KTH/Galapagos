static void put_bits(Jpeg2000EncoderContext *s, int val, int n) 
{
    if (s == NULL) 
        return;
    
    for(int i = n; i > 0; i--)
    {
        if(s->bit_index == 8)
        {
             s->bit_index = (*s->buf != 0) ? 1 : 0;
             *(++s->buf) = 0;
        }
        unsigned mask = val << (7 - s->bit_index++);
        *s->buf |= mask;
    }
}