static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    int value;
    int bit;

    for(; n > 0; n--) {
        res = res << 1;
        if (s->bit_index == 0) {
            value = bytestream2_get_byte(&s->g);
            s->bit_index = (value != 0xFFu) ? 8 : 7;
        }
        s->bit_index--;
        
        bit = bytestream2_peek_byte(&s->g);
        res |= (bit >> s->bit_index) & 1;
    }
    return res;
}