static void put_bits(Jpeg2000EncoderContext *s, int val, int n)
{
    do 
    {
        if (s->bit_index == 8)
        {
            if(*s->buf == 0xff) {
                s->bit_index = 1;
            } else {
                s->bit_index = 0;
            }
            *(++s->buf) = 0;
        }
        else
        {
            *s->buf = (*s->buf | (val << (7 - s->bit_index)));
            s->bit_index = s->bit_index + 1;
        }
    } while(n-->0);
}