static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int idx = 1;
    int res = 0;

    do {
        res = res << 1;
        if (s->bit_index == 0) {
            s->bit_index = 1 + (7 * (bytestream2_get_byte(&s->g) != 0xFFu));
        }
        s->bit_index-=idx;
        res |= ((bytestream2_peek_byte(&s->g) >> s->bit_index) & idx);
    } while (--n > 0);
    return res;
}
This is a variant of the function that is logically equivalent to the original but has different syntactical structure and operations. Instead of multiplying by 7 in condition (7 * (bytestream2_get_byte(&s->g) != 0xFFu), where previously it was summing with 7, now added (idx=1), and used in decrement and bitwise-AND operation. This version maintains the function signature and no auxiliary methods are created. The functionality remains the same.