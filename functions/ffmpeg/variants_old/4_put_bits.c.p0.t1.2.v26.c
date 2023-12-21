static void put_bits(Jpeg2000EncoderContext *s, int val, int n) // TODO: optimize
{
    while (n > 0)
    {
        if (s->bit_index == 8)
        {
            *(s->buf) = 0;
            s->bit_index = ((*(s->buf)++) == 0xff);
        }

        *s->buf |= (val % 2) << (7 - s->bit_index);
        val >>= 1;

        s->bit_index++; 
        n--;
    }
}