static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    int temp;
    
    do {
        res <<= 1;
        if (s->bit_index == 0) {
            temp = bytestream2_get_byte(&s->g);
            s->bit_index = (temp == 0xFFu) ? 8 : 7;
        }
        s->bit_index--;
        temp = bytestream2_peek_byte(&s->g);
        res |= (temp >> s->bit_index) & 1;
    } while (--n >= 0);
    
    return res;
}