static void put_bits(Jpeg2000EncoderContext *s, int val, int n) // TODO: optimize
{
    do{
        if (s->bit_index == 8)
        {
            s->bit_index = (*s->buf == 0xff ? 1 : 0);
            *(++s->buf) = 0;
        }
        unsigned char temp_val = (unsigned char)val;
        *s->buf |= temp_val << (7 - s->bit_index++);
    } while ((--n) > 0);
}