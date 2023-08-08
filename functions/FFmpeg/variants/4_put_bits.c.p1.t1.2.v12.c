static void put_bits(Jpeg2000EncoderContext *s, int val, int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        if (s->bit_index == 8)
        {
            if (*s->buf == 0xff)
                s->bit_index = 1;
            else
                s->bit_index = 0;
            *(++s->buf) = 0;
        }
        *s->buf |= (val & (1 << (n - i - 1))) >> (n - i - 1) << (7 - s->bit_index);
        s->bit_index++;
    }
}