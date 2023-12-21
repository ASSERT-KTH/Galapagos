static void put_bits(Jpeg2000EncoderContext *s, int val, int n)
{
    for (; n > 0; n--){
        if(s->bit_index == 8)
        {
            if (*s->buf == 0xff) 
                s->bit_index = 1;
            else 
                s->bit_index = 0;
            *(++s->buf) = 0;
        }

        if(n > 0)
            *s->buf |= (val << (7 - s->bit_index) & 0xFF);
        s->bit_index++;
    }
}