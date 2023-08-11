static void put_bits(Jpeg2000EncoderContext *s, int val, int n) // TODO: optimize
{
    for(; n; --n)
    {
        if (s->bit_index == 8)
        {
            s->bit_index = (int)(*s->buf == 0xff);
            *(s->buf + 1) = 0;
            s->buf++;
        }
        *(s->buf) |= (val << (7 - s->bit_index));
        s->bit_index++;
    }  
}