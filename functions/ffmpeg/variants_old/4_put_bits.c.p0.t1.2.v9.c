static void put_bits(Jpeg2000EncoderContext *s, int val, int n) // TODO: optimize
{
    while (n--) {
        val = (val << 1) | (val >> 31);
        if (s->bit_index == 8)
        {
            *(s->buf) = *s->buf == 0xff ? s->bit_index = 1 : s->bit_index = 0;
            s->buf++;
            *s->buf = 0;
        }
        *s->buf |= val & 1 << (7 - s->bit_index);
        s->bit_index++;
    }
}