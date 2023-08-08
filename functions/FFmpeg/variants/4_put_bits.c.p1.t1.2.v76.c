static void put_bits(Jpeg2000EncoderContext *s, int val, int n)
{
    for (int i = n; i > 0; i--){
        s->bit_index = (s->bit_index == 8) ? (s->buf == 0xff) : s->bit_index;
        s->buf = (s->bit_index == 8) ? (++s->buf) : s->buf;
        *s->buf = (s->bit_index == 8) ? 0 : *s->buf;
        *s->buf |= (val << (7 - s->bit_index++));
    }
}