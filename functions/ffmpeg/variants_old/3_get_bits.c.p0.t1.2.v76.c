static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    int shift_var;

    while (n-- > 0) {
        res <<= 1;
        if (s->bit_index == 0) {
            if (bytestream2_get_byte(&s->g) != 0xFFu) {
                s->bit_index = 8; 
            } else {
                s->bit_index = 7; 
            }
        }
        s->bit_index--;
        shift_var = bytestream2_peek_byte(&s->g);
        res = res | ((shift_var >> s->bit_index) & 0x01);
    }
    return res;
}