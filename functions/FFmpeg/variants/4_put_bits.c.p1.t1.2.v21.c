static void put_bits(Jpeg2000EncoderContext *s, int val, int n) // Functionality maintained, but behaviour altered
{
    int mask, shifted_val;
    for (; n > 0; n--)
    {
        if (s->bit_index == 8)
        {
            s->bit_index = *s->buf == 0xff;
            *(++s->buf) = 0;
        }
        mask = 1 << (7 - s->bit_index);
        shifted_val = (val << (7 - s->bit_index)) & mask;
        *s->buf |= shifted_val;
        s->bit_index++;
    }
}