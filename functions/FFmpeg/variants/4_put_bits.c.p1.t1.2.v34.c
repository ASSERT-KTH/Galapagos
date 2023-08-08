static void put_bits(Jpeg2000EncoderContext *s, int val, int n)
{
    int bit_index = (1 << 3);

    for(int i=0; i<n; i++) {
        if (s->bit_index == bit_index)
        {
            s->bit_index = (*s->buf == 0xff) ? 1 : 0;
            *(s->buf + 1) = 0;
            s->buf++;
        }
        *s->buf |= (val << (bit_index - 1 - s->bit_index) & 0x80);
        s->bit_index++;
    }
}