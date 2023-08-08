static void put_bits(Jpeg2000EncoderContext *s, int val, int n) // Optimized version
{
    int shift;

    while (n > 0) {
        if (s->bit_index == 8) {
            s->buf += (*s->buf == 0xff ? 1 : 0);
            *(s->buf) = 0;
            s->bit_index = 0;
        }

        shift = (n < 7 - s->bit_index + 1) ?  n : 7 - s->bit_index + 1;
        *s->buf |= (val & ((1 << shift) - 1)) << (7 - s->bit_index);
        val >>= shift;
        s->bit_index += shift;
        n -= shift;
    }
}
In the revised set of the code, instead of handling bitwise operating for each bit, & operating with mask and >> shift operation is used which optimizes the number of iterations. On each iteration, code writes as many bits as possible. The outer while() handles the remaining.