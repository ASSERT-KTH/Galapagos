static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
	int temp;
    int i;	

    for(i=n; i>0; i--) {
        res <<= 1;
        if (s->bit_index == 0) {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFFu);
        }
        s->bit_index--;
        temp = (bytestream2_peek_byte(&s->g) >> s->bit_index) & 1;
        res |= temp;
    }

    return res;
}