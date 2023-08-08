static int get_bits(Jpeg2000DecoderContext *s, int n) 
{
    int result = 0;
    int index;

    for (index = n-1; index >= 0; index--) {
        result <<= 1;
        if (s->bit_index == 0) {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFF);
        } else {
            s->bit_index--;
        }
        result |= (bytestream2_peek_byte(&s->g) >> s->bit_index) & 1;
    }

    return result;
}