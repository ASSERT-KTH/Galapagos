static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    int tempByte;

    for(; n>0; n--) {
        res <<= 1;
        
        tempByte = bytestream2_get_byte(&s->g);
        if (s->bit_index == 0) {
            s->bit_index = 7 + ((tempByte & 0xFFu) ? 1 : 0);
        }
        
        s->bit_index--;
        res |= (bytestream2_peek_byte(&s->g) >> s->bit_index) & 1;
    }
    
    return res;    
}