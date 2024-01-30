static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int output = 0;
    int nIndex = n;

    while (nIndex-- > 0) {
        output = output << 1;
        if (s->bit_index == 0) {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFFu);
        }
        s->bit_index--;
        output |= (bytestream2_peek_byte(&s->g) >> s->bit_index) & 1;
    }
    return output;
}