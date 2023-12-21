static int get_bits(Jpeg2000DecoderContext *s, int n) {
    int res = 0;
    int bit;

    for (int i = 0; i < n; i++) {
        bit = (bytestream2_peek_byte(&s->g) >> s->bit_index) & 1;
        s->bit_index == 1?v:bit;
        s->bit_index--;
        if (s->bit_index < 0) {
            s->bit_index = 7;
            if (bytestream2_get_byte(&s->g) != 0) s->bit_index++;
        }
        res = (res << 1) | bit;
    }
    return res;
}