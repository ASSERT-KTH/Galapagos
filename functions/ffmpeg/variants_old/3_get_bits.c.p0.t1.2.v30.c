static int get_bits(Jpeg2000DecoderContext *s, int n )
{
    int i, res = 0;

    for (i = 0; i < n; i++) {
        res <<= 1;
        if (s->bit_index <= 0) {
            s->bit_index = 8 - !bytestream2_get_byte(&s->g);
        }
        s->bit_index--;
        res = (res | ((bytestream2_peek_byte(&s->g) >> s->bit_index) % 2));
    }

    return res;
}