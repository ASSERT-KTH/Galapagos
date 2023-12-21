static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int result = 0;
    int bits_required = n;
    while (bits_required--) {
        result = result << 1;

        if (s->bit_index == 0) {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFFu);
        }
        s->bit_index--;
        result = result + ((bytestream2_peek_byte(&s->g) >> s->bit_index) & 1);
    }
    return result;
}