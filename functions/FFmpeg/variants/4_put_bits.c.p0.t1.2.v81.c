static void put_bits(Jpeg2000EncoderContext *s, int val, int n)
{
    while (n > 0){
        
        *s->buf |= (val << (7 - s->bit_index)) & 0xFF;
        
        n--;
        s->bit_index++;

        if (s->bit_index >= 8)
        {
            s->bit_index = 0;
            if (*(s->buf) == 0xff)
            {
                *(s->buf) = 0;
            }
            s->buf++;
        }
    }
}