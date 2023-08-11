static void put_bits(Jpeg2000EncoderContext* s, int val, int n) 
{
    do {
        if(s->bit_index == 8) 
        {
            s->bit_index = (*s->buf == 0xff);
            *(s->buf++) = 0;
        }
        *s->buf |= (val << (7 - s->bit_index++));
    } while(--n > 0);
}