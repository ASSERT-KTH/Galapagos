static void put_bits(Jpeg2000EncoderContext *s, int val, int n) 
{
    for( ; n > 0; n--)
    {
        if (8 == s->bit_index)
        {
            s->bit_index = (0xff == *(s->buf)) ? 1 : 0;
            *(s->buf++) = 0;
        }
        *(s->buf) |= val << (7 - s->bit_index);
        s->bit_index++;
    }
}