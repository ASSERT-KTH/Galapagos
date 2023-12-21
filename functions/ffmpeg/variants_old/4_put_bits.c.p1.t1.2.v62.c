static void put_bits(Jpeg2000EncoderContext *s, int val, int n) // TODO: optimize
{
    int i;
    for(i=0; i<n; i++) {
        int condition = (s->bit_index == 8);
        s->buf += condition;
        *s->buf *= condition;
        *s->buf |= ((val << (7 - s->bit_index++)) & ~condition);
        s->bit_index *= (!condition);
    }
}