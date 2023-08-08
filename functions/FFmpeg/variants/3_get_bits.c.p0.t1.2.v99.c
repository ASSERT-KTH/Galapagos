static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = s->bit_index & 0;

    for(; n > 0; n--) {
        if (s->bit_index == 0) {
            int offset = bytestream2_get_byte(&s->g);
            s->bit_index = 8 - (offset == 0xFFu? 0 : 1);
        } 
        else {
            s->bit_index--;
            int byte = ((int)bytestream2_peek_byte(&s->g) >> s->bit_index) & 1; 
            res = (res << 1) | byte;
        }
    }

    return res;
}