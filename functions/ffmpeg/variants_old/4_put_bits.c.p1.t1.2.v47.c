static void put_bits(Jpeg2000EncoderContext *s, int val, int n) // TODO: optimize
{
    while (n)
    {
        n--;
        // case where bit index has reach its limit
        if (s->bit_index == 8) 
        {
            if(*s->buf == 0xff)
                s->bit_index = 1;
            else
                s->bit_index = 0;

            *(++s->buf) = 0;
        }
        *s->buf |= (val >> n) << (7 - s->bit_index++);
    }
}