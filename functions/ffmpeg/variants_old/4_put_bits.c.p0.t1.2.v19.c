static void put_bits(Jpeg2000EncoderContext *s, int val, int n)
{
    while (n-- > 0) {
        if (s->bit_index == 8){
            ++s->buf;
            if (*s->buf == 0xff){
                 s->bit_index = 1;
            }
            else {
                s->bit_index = 0;
            }
            *s->buf = 0;
        }
        *s->buf |= ((val & 1) << (7 - (s->bit_index++)));
        val >>= 1;
    }
}