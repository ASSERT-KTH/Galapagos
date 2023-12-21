static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0, draw_bit = 0;

    for(s->bit_index--; n > 0; n--) {
        if (s->bit_index == 0) {
            s->bit_index = 8 - !!(bytestream2_get_byte(&s->g) != 0xFFu);
        } else {
            s->bit_index -= 1;
        }
        draw_bit = (bytestream2_peek_byte(&s->g) >> s->bit_index) & 0x01;
        res = (res<<1)|draw_bit;
    }
    
    return res;
}