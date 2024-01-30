static void put_bits(Jpeg2000EncoderContext *s, int val, int n)
{
    do{
        if (s->bit_index == 8)
        {
            (*s->buf)++;
            s->bit_index = 0;
            if (*s->buf == 0xff) {
               *s->buf = 0;
            }
        }
        else
        {
            *s->buf |= (val << (7 - s->bit_index));
            val >>= 1;
        }
        s->bit_index += (s->bit_index < 8);
    } while (--n > 0);
}