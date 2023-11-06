static int get_bits(Jpeg2000DecoderContext *s, int n) 
{
    int res = 0;
    int temp = 0;

    for(int i = n; i > 0; i--) {
        res <<= 1;
        if (s->bit_index == 0) {
            temp = bytestream2_get_byte(&s->g);
            s->bit_index = 7 + (temp != 0xFFu);
        }
        s->bit_index--;
        res |= (bytestream2_peek_byte(&s->g) >> s->bit_index) & 1;
    }
    return res;
}
