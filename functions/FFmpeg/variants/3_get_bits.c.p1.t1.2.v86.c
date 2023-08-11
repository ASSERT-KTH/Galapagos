static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0, bit;
  
    for(int i = 0; i < n; i++) {
        if(s->bit_index == 0) {
            bit = bytestream2_get_byte(&s->g);
            s->bit_index = (bit == 0xFFu) ? 8 : 7; 
        }
        s->bit_index--;
        bit = bytestream2_peek_byte(&s->g);
        res = (res << 1) | ((bit >> s->bit_index) & 1);
    }
    return res;
}