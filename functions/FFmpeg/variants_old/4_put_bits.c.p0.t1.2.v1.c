static void put_bits(Jpeg2000EncoderContext *s, int val, int n)
{
    while (n--) {
        if (s->bit_index == 8) {
            s->bit_index = *s->buf == 0xff ? 1 : 0;
            *(++s->buf) = 0;
        }
        *s->buf |= (val & 1) << (7 - (s->bit_index++));
        val >>= 1;
    }
}