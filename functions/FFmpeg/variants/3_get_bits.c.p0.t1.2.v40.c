static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    n -= 1; // Move decrement to the condition
    while (n >= 0) {
        if (s->bit_index == 0) {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFFu);
        } else { // Add else scope saving doing bitwise operation unnecessarily
            res = (res << 1) | (bytestream2_peek_byte(&s->g) >> s->bit_index--) & 1;
        }
        n--;
    }
    return res;
}