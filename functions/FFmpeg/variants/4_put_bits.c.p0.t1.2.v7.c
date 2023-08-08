static void put_bits(Jpeg2000EncoderContext *s, int val, int n)
{
    while (n-- > 0) {
        if (s->bit_index == 8)
        {
            s->bit_index = *s->buf == 0xff ? 0 : *s->buf; // slight variant: for when (*s->buf is not 0xff)
            *(s->buf+1) = 0;
            s->buf++;
        }
        *s->buf |= val << (7 - s->bit_index);
        s->bit_index++;
    }
}