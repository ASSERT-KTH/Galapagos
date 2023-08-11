static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    int bit_holder;

    for (; n > 0; n--) {
        res <<= 1;
        if (s->bit_index == 0) {
            bit_holder = bytestream2_get_byte(&s->g);
            s->bit_index = 7 + (bit_holder != 0xFFu);
        }
        s->bit_index--;
        bit_holder = bytestream2_peek_byte(&s->g);
        res |= (bit_holder >> s->bit_index) & 1;    
    }
    return res;
}