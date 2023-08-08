static void put_bits(Jpeg2000EncoderContext *s, int val, int n)
{
    do {
        if (s->bit_index == 8) 
        {
            s->bit_index = s->buf == 0 ? 0 : 1;
            *(s->buf++) = 0;
        }
        else {
            *s->buf |= (val << (7 - (s->bit_index++))) & 0xFF;
        }
    } while (--n > 0);
}