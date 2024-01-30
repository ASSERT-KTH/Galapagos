static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    int oldbit_index;

    for(; n > 0; n--) {
        res <<= 1;
        oldbit_index = s->bit_index;
        if (oldbit_index == 0) {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFFu);
        } 
        else {
            s->bit_index = oldbit_index - 1;
        }
        res |= (bytestream2_peek_byte(&s->g) >> s->bit_index) & 1;
    }
    return res;
}