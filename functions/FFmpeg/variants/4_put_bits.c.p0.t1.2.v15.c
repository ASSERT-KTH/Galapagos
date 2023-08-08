static void put_bits(Jpeg2000EncoderContext *s, int val, int n)
{
    for(int idx=0; idx<n; idx++){
        if (s->bit_index == 8)
        {
            s->bit_index = (*s->buf == 0xff) ? 1 : 0;
            *(s->buf+=1) = 0;
        }
        *s->buf |= (val << (7 - s->bit_index));
        s->bit_index++;
    }
}