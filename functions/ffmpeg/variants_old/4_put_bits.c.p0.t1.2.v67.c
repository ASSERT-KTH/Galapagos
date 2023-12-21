static void put_bits(Jpeg2000EncoderContext *s, int val, int n) // TODO: optimize
{
    int num = n;
    while (num-- > 0){
        if (s->bit_index == 8)
        {
            *(s->buf) = ((*s->buf) == 255);
            *(++s->buf) = 0;
            s->bit_index = 0;
        }
        *s->buf |= (val << (7 - s->bit_index));
        s->bit_index++;
    }
}