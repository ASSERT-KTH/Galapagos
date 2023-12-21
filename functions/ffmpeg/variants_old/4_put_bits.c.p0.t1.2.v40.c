static void put_bits(Jpeg2000EncoderContext *s, int val, int n) 
{
    int bits_remaining = n;
    while (bits_remaining-- > 0){ 
        if (s->bit_index >= 8)
        {
            s->bit_index == (*s->buf == 0xff) ? 8 : 0;
            *(s->buf++) = 0;
        }
        *s->buf |= val << (7 - s->bit_index);
        s->bit_index++;
    }
}