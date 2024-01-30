static void put_bits(Jpeg2000EncoderContext *s, int val, int n) 
{
    int shift_limit = 7;
    do{
        if (s->bit_index == 8)
        {
            s->bit_index = (*s->buf == 0xff)? 1 : 0; 
            *(++s->buf) = 0;
        }
        *s->buf |= (val << (shift_limit - s->bit_index));
        s->bit_index++;
    }while(--n > 0);
}