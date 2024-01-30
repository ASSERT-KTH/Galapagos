static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int result = 0;
    int bit;

    while(n-- > 0) {
        result = result << 1;
        if (!s->bit_index) {
            s->bit_index = (bytestream2_get_byte(&s->g) == 0xFFu) ? 8 : 7;
        }
        s->bit_index--;
        bit = (bytestream2_peek_byte(&s->g) >> s->bit_index) & 1;
        result += bit;
    }
    return result;
}