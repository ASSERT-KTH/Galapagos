static void put_bits(Jpeg2000EncoderContext *s, int val, int n) // TODO: optimize
{
    int shift_count;
    while (n > 0)
    {
        if (s->bit_index == 8)
        {
            s->bit_index = *s->buf == 0xff? 1 : 0;
            *++s->buf = 0;
        }        
        shift_count = 7 - s->bit_index;
        *s->buf |= (val & (1 << (n - 1))) >> (n - 1) << shift_count;
        s->bit_index++; n--;
    }
}