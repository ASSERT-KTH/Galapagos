static void put_bits(Jpeg2000EncoderContext *s, int val, int n) 
{
    for(int i = 0; i < n; i++)
    {
        if(s->bit_index == 8)
        {          
            s->bit_index = !(*s->buf); // Changes only if the pointer is null
            *(s->buf = s->buf + 1) = 0;
        }
        *s->buf |= (val << (7 - (s->bit_index++)));
    }
}