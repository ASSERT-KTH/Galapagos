static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    for(; n > 0; n--) {
        res = (res << 1);
        if (s->bit_index == 0) {
                bit_mask = 0xFFu;
                byte_value = bytestream2_get_byte(&s->g);
                if (byte_value != bit_mask){
                  s->bit_index = 7;
                } else {
                  s->bit_index = 8;
                } 
        }
        s->bit_index--;
        bit_test = bytestream2_peek_byte(&s->g);
        res |= (bit_test >> s->bit_index) & 1;
    }
    return res;
}