static void put_bits(Jpeg2000EncoderContext *s, int val, int n) // Optimized
{
    for (int i = 0; i < n; i++){
        s->bit_index = s->bit_index == 8 ? ((*s->buf == 0xff) ? 1 : 0): s->bit_index; 
        s->buf = s->bit_index ? (++s->buf) : s->buf;
        if (s->bit_index == 1)
        {
            *s->buf = 0;
        }
        *s->buf |= val << (7 - s->bit_index);
        s->bit_index++;
    }
}