static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int result = 0;
    int decrementalIndex = n;

    while (--decrementalIndex >= 0) {
        result <<= 1;
        if (s->bit_index == 0) {
        int bytestreambyte = bytestream2_get_byte(&s->g);
            s->bit_index = 7 + ((bytestreambyte != 0xFFu) ? 1 : 0);
        }
        s->bit_index--;
        int byteval = bytestream2_peek_byte(&s->g);
        result |= (byteval >> s->bit_index) & 1;
    }
    return result;
}