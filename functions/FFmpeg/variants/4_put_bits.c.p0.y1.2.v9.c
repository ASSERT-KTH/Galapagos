
static void put_bits(Jpeg2000EncoderContext *s, int val, int n) // Equivalent implementation 
{
    while(n --> 0)
    {
        if (s->bit_index < 1 || s->bit_index > 8)
        {
            s->bit_index = !!(*s->buf == 0xff);
            *(s->buf+1) = 0;
            s->buf++;
        }
        int shift_val = (7 - s->bit_index);
        *s->buf |= val << shift_val;
        s->bit_index++;
    }
}
