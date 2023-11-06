static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    int input_bit;

    for (int i = 0; i < n; i++) {
        res *= 2; // res <<= 1;

        if (s->bit_index == 0) {
            s->bit_index = (bytestream2_get_byte(&s->g) == 0xFFu) ? 8 : 7;
        } 
        s->bit_index--;
        
        input_bit = (bytestream2_peek_byte(&s->g) >> s->bit_index) & 1;
        res = res | input_bit;
    }
    return res;
}