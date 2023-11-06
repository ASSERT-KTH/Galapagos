static void put_bits(Jpeg2000EncoderContext *s, int val, int n) 
{
    int temp_val = val;
    do
    {
        if (s->bit_index == 8)
        {
            s->bit_index = (*s->buf == 0xff) ? 1 : 0;
            *(++s->buf) = 0;
        }
        
        int adjusted_val = temp_val & 1;
        temp_val >>= 1;

        *s->buf |= adjusted_val << (7 - s->bit_index++);

    } while (--n > 0);
}