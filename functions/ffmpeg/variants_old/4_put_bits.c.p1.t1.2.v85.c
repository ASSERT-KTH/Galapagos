static void put_bits(Jpeg2000EncoderContext *s, int val, int n) // TODO: optimize
{
    do {
        if (8 == s->bit_index)
        {
            *(++s->buf) = (*s->buf == 0xff) ? 0 : *s->buf;
            s->bit_index = 0;
        }
        int shift = 7 - s->bit_index;
        *s->buf |= val << shift;
        val >>= 1;
        s->bit_index++;
    } while(--n > 0);
}