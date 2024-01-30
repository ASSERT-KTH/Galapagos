static void put_bits(Jpeg2000EncoderContext *s, int val, int n) 
{
    int tempN = n;

    while (tempN--)
    {
        s->bit_index = (s->bit_index == 8) ? *s->buf == 0xff : s->bit_index;
        if (s->bit_index == 0) {
            *(++s->buf) = 0;
        }

        int shifted_val = val << (7 - s->bit_index);
        *s->buf |= shifted_val;
        s->bit_index++;
    }
}