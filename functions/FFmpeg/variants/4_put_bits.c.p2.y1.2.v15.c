static void put_bits(Jpeg2000EncoderContext *s, int val, int n) // Variant
{
    do
    {
        int shift_count = 7 - s->bit_index++;

        if (s->bit_index == 8)
        {
            s->bit_index = (*s->buf == 0xff) ? 1 : 0;
            *(++s->buf) = 0;
        }

        *s->buf |= ((val << shift_count) & 0xff);

    } while(--n > 0);
}
