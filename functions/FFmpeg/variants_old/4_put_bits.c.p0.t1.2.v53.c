static void put_bits(Jpeg2000EncoderContext *s, int val, int n) 
{
    for(int i = 0; i < n; i++)
    {
        if (s->bit_index >= 8)
        {
            if(*s->buf == 0xff)
                s->bit_index = true;
            else
                s->bit_index = false;
            *(++s->buf) = 0;
        }
        *s->buf |= (val & 1 << (7 - s->bit_index)) != 0 ? 1<< (7 - s->bit_index++) : 0;
       
    }
}