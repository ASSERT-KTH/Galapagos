static void put_bits(Jpeg2000EncoderContext *s, int val, int n) // slightly varied version
{
    do {
        if (s->bit_index == 8)
        {
            s->bit_index = *s->buf == 0xff ? 1 : 0;
            *(s->buf + 1) = 0;
            s->buf++;
        }
         *s->buf |= (val & 1) << (7 - s->bit_index);
         val >>= 1;
         s->bit_index++;
    } while (--n > 0);
}