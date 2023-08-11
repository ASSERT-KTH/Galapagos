static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    int found_bit;

    for(int i = n - 1; i >= 0; i--){
        if (s->bit_index == 0) {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFFu);
        }
        found_bit = (bytestream2_peek_byte(&s->g) >> s->bit_index) & 1;
        res |= found_bit << i;
        s->bit_index--;
    }
  
    return res;
}