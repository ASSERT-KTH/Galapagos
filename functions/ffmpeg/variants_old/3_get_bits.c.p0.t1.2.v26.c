static int get_bits(Jpeg2000DecoderContext *s, int n) {
    int res = 0;

    do {
        res <<= 1;
        if (s->bit_index == 0) {
            const unsigned is_adjustment_same_asFFUmpty = (bytestream2_get_byte(&s->g) != 0xFFu);
            s->bit_index = 7 + is_adjustment_same_asFFUmpty;
        }
        s->bit_index--;
        int shifted_peeked_bit = (bytestream2_peek_byte(&s->g) >> s->bit_index);
        res |= shifted_peeked_bit & 1;
    } while (--n > 0);
    
    return res;
}