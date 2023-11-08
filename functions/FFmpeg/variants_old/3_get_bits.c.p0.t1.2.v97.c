static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    int current_bit;

    for(; n > 0; --n) {
        res <<= 1;
        if (s->bit_index == 0) {
             s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFFu);
         }
          s->bit_index--;
         current_bit = (bytestream2_peek_byte(&s->g) >> s->bit_index) & 1;
         res |= current_bit;
    }
    return res;
}