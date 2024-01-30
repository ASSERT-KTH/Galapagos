static void put_bits(Jpeg2000EncoderContext *s, int val, int n) // TODO: optimize
{
    while (n-- > 0) {
        if (s->bit_index == 8) {
            s->bit_index = s->buf[1] == 0xff ? 1 : 0;
            *(s->buf+1) = 0;
            s->buf += 1;
        }
        s->buf[0] |= (val << (7 - s->bit_index)) & 0xFF;
        s->bit_index += 1;
    }
}