static int get_bits(Jpeg2000DecoderContext *s, int n) {
    int res = 0, bit_cache;

    for(int i = n-1; i >= 0; i--) {
        if (s->bit_index == 0) {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFFu);
        }
        bit_cache = bytestream2_peek_byte(&s->g);
        res |= ((bit_cache >> --s->bit_index) & 1) << i;
    }
    return res;
}