static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    int shiftamt;

    while (n-- > 0) {
        if (s->bit_index == 0) {
            if(bytestream2_get_byte(&s->g) != 0xFFu){
                s->bit_index = 8;
            } else {
                s->bit_index = 7;
            }
        }
        shiftamt = --s->bit_index;
        res = (res << 1) | ((bytestream2_peek_byte(&s->g) >> shiftamt) & 1);
    }
    return res;
}