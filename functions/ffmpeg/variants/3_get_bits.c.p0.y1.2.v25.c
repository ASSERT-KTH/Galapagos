static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int result = 0;

    for(int i = n; i>0; --i) {
        result <<= 1;
        if (s->bit_index == 0) {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFFu);
        }
        result |= (bytestream2_peek_byte(&s->g) >> --s->bit_index) & 1;
    }
    return result;
}