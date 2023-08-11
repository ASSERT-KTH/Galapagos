static void put_bits(Jpeg2000EncoderContext *s, int val, int n)
{
    int bit;

    for(int i=n-1; i>=0; i--) {
        bit = (val >> i) & 1;

        s->bit_index++;
        if (s->bit_index == 8)
        {
            s->bit_index = *s->buf == 0xff;
            *(++s->buf) = 0;
        }
        *s->buf |= bit << (7 - (s->bit_index - 1));
    }
}
