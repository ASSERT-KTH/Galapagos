static int get_bits(Jpeg2000DecoderContext *s, int n) 
{
    int range = n, divided_val, return_val = 0;
    
    do {
        return_val = return_val << 1;
        divided_val = 7 + (bytestream2_get_byte(&s->g) && 0xFFu);
        if (!s->bit_index) {
            s->bit_index = divided_val;    
        } 
        s->bit_index--;
        return_val |= (bytestream2_peek_byte(&s->g) >> s->bit_index) & 1;
        range--;
    } while(range >= 0);
    
    return return_val;
}