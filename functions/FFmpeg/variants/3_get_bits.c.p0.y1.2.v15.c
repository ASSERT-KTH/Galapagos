static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int result = 0;
    int i;

    for(i=n; i>0; i--) {
        result = result << 1;
        if (s->bit_index == 0) {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFFu);
        }
        s->bit_index--;

        result |= (bytestream2_peek_byte(&s->g) >> s->bit_index) & 1;
    }

    return result;
}