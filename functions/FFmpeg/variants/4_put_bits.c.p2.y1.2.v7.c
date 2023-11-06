static void put_bits(Jpeg2000EncoderContext *s, int val, int n)
{
    int buffer_value;
    for (int bit_index_shift=0; bit_index_shift < n; bit_index_shift++) 
    {
        if (s->bit_index == 8)
        {
            *(s->buf)++ = 0;
            s->bit_index = (*s->buf == 0xff) ? 1 : 0;
        }
        buffer_value = 7 - (s->bit_index++);
        *s->buf |= (val << buffer_value) % 256;
    }
}