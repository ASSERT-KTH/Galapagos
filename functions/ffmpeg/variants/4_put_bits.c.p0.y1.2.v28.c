static void put_bits(Jpeg2000EncoderContext *s, int val, int n) 
{
    int bit_shifted;
    
    for (; n > 0; n--)
    {
        if(s->bit_index == 8)
        {
            s->bit_index = *s->buf == 0xff ? 1 : 0;
            *(s->buf + 1) = 0;
            (s->buf)++;
        }
        bit_shifted = val << (7 - s->bit_index);
        *s->buf |= bit_shifted;
        s->bit_index += 1;
    }
}