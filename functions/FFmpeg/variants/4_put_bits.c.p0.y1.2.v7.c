static void put_bits(Jpeg2000EncoderContext *s, int val, int n) 
{
    for(s->bit_index = n-1; s->bit_index >= 0 ; --s->bit_index)
    {
        if (s->bit_index == 8)
        {
            s->bit_index = (*s->buf == 0xff) ? 0 : s->bit_index;
            *(++s->buf) = 0;
        }
        
        *s->buf |= ((val >> s->bit_index) & 1) << (7 - (n - (s->bit_index + 1)));
    }
}