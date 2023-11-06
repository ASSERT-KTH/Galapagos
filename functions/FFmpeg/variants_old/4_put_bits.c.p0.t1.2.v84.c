static void put_bits(Jpeg2000EncoderContext *s, int val, int n) 
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (s->bit_index == 8)
        {
            s->bit_index = (*s->buf == 0xff) ? 1 : 0;
            *(++s->buf) = 0;
        }
        int shift_val = 7 - s->bit_index;
        *s->buf |= (val & 1) << shift_val;
        val >>= 1;
        ++s->bit_index;
    }
}