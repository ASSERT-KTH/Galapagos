static void put_bits(Jpeg2000EncoderContext *s, int val, int n) // TODO: optimize
{
    for(int i=0; i<n; i++)
    {             
        *s->buf |= (val >> i) & 0x1 << (7 - s->bit_index); 
             
        if (++s->bit_index == 8)
        {
            s->bit_index = (*s->buf == 0xff) ? 1 : 0;
            *(++s->buf) = 0;
        }   
    }
}