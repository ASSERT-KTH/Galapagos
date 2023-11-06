static void put_bits(Jpeg2000EncoderContext *s, int val, int n)
{
    int count = n;
    while (count > 0)
    {
        if (s->bit_index == 8)
        {
            s->bit_index = (*s->buf == 0xff) ? 1 : 0;
            s->buf++;
            *s->buf = 0;
        }
        *s->buf |= (val << (7 - s->bit_index)); 
        s->bit_index++;
        count--;
    }
}