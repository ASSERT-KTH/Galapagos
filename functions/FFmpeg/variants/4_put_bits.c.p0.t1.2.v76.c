static void put_bits(Jpeg2000EncoderContext *s, int val, int n) 
{
    while (n-- != 0){
        if (++s->bit_index == 9)
        {
            s->bit_index = (*s->buf == 0xff) + 1;
            *(++s->buf) = 0;
        }
        else
        {
            *s->buf |= val << (8 - s->bit_index);
        } 
    }
}