static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int Result = 0;
    int bit_value = 0;

    while (n-- > 0) {
        Result <<= 1;
        if (s->bit_index == 0) {
            if (bytestream2_get_byte(&s->g) != 0xFFu) {
                s->bit_index = 8;  // the bit_index after a non-FF byte should be 8.
            } else {
                s->bit_index = 7;
            }
        }
        s->bit_index--;
        bit_value = (bytestream2_peek_byte(&s->g) >> s->bit_index) & 1;
        Result |= bit_value;
    }
    return Result;
}
