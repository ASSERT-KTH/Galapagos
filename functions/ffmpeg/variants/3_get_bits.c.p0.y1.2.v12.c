static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int bits = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (s->bit_index == 0) {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFFu);
        }
        
        bits |= ((bytestream2_peek_byte(&s->g) >> --s->bit_index) & 1) << i;
    }

    return bits;
}