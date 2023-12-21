static void put_bits(Jpeg2000EncoderContext *s, int val, int n) 
{
    int pos = 7;
    int temp_val;
    do {
        if (s->bit_index == 8) 
        {
            s->bit_index = *s->buf == 0xff ? 1 : 0;
            *(s->buf + 1) = 0;
            s->buf += 1;
        }
        temp_val = (val & 1) << (pos - s->bit_index);
        *s->buf |= temp_val;
        val >>= 1;
    } while (s->bit_index++, n-- > 0);
}