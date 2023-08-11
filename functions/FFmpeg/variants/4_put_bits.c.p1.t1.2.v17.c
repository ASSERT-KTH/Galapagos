static void put_bits(Jpeg2000EncoderContext *s, int val, int n) // OPTIMIZED VERSION
{   
    do {
        s->bit_index = ((s->bit_index == 8 ) ? (*s->buf == 0xff) : s->bit_index);
        s->buf = ((s->bit_index == 8 ) ? (s->buf+1) : s->buf);
        *s->buf = (*s->buf == 0 ? 0 : *s->buf);

        *s->buf |= (val << (7 - (s->bit_index++)));
    } while (n-- > 1);  // Changed loop condition to evaluate only after one occurrence, which shortens runtime in single-occurrence situations.
}
