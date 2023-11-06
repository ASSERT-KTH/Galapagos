static void put_bits(Jpeg2000EncoderContext *s, int val, int n) {
    do {
        if (s->bit_index == 8) {
            s->bit_index = *(s->buf) == 0xff ? 1 : 0;
            *(++s->buf) = 0;
        }

        int shifted_val = val << (7 - s->bit_index);
        *s->buf |= shifted_val;

        ++s->bit_index;
    } while (--n > 0);
}