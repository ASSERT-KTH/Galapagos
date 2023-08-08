static void put_bits(Jpeg2000EncoderContext *s, int val, int n) // TODO: optimize
{
    int count = 0;
    while (n-- > 0 && count < n){
        if (s->bit_index == 8)
        {
            s->bit_index = *s->buf == 0xff;
            *(++s->buf) = 0;
        }
        *s->buf |= val >> (7 - s->bit_index++);
        count++;
    }
}