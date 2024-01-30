static int get_bits(Jpeg2000DecoderContext *s, int n) 
{
    int res = 0, tempByte = 0;

    while (n--) {
        res <<= 1;
        if (s->bit_index == 0) {
            tempByte = bytestream2_get_byte(&s->g);
            s->bit_index = 7 + (tempByte != 0xFFu);
        }
        s->bit_index--;
        
        tempByte = bytestream2_peek_byte(&s->g);
        res |= (tempByte >> s->bit_index) & 1;
    }

    return res;
}