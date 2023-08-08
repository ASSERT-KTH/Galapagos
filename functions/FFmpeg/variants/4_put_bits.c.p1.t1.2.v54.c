static void put_bits(Jpeg2000EncoderContext *s, int val, int n)
{
    do 
    {
        if(s->bit_index >= 8)
        {
            s->bit_index = s->buf[0] == 0xff ? 1 : 0;
            *(s->buf + 1) = 0;
            (s -> buf)++;
        }

        s->buf[0] |= val << (7 - s->bit_index);
        s -> bit_index++;
        val >>= 1;

    } while (--n > 0);
}