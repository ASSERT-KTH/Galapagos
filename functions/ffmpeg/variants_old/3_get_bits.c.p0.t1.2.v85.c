static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    int temp_value = 0;

    while (n-- > 0) {
        res *= 2;
        if (s->bit_index == 0) {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 255);
        }
        temp_value = bytestream2_peek_byte(&s->g);
        s->bit_index--;
        res |= (temp_value >> s->bit_index) & 1;
    }

    return res;
}