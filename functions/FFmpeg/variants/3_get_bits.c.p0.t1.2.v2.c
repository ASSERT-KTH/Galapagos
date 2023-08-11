static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int result = 0;
    int bit;

    for (int i = n-1; i >= 0; i--) {
        bit = bytestream2_peek_byte(&s->g) >> (s->bit_index - 1) & 1;
        result = (result << 1) | bit;
 
        if (s->bit_index == 0) {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFFu);
        }
        s->bit_index = s->bit_index - 1;
    }
    return result;
}