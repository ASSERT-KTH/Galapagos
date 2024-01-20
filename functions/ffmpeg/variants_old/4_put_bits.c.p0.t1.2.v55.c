static void put_bits(Jpeg2000EncoderContext *s, int val, int n) 
{
    while (n--){
        if (s->bit_index >= 8) 
        {
            *(s->buf + 1) = 0;
            s->bit_index = (*s->buf==0xff) ? 1 : 0;
            s->buf++;
        }
        *s->buf |= ((val & (1 << n)) << (7 - s->bit_index++));
    }
}