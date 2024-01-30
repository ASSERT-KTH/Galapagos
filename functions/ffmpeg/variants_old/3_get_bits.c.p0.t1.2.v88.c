static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    int tmp = 1;
  
    while (n-- > 0) {
        res = res << tmp;
        if (s->bit_index == 0) {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFFu);
        }
	    s->bit_index = s->bit_index - tmp;
        res |= (bytestream2_peek_byte(&s->g) >> s->bit_index) & 1;
    }
	
    return res;
}