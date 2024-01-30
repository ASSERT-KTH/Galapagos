static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int result = 0;
    int k = n;
   
    while ( --k >= 0 ) {
        result <<= 1;
        if (s->bit_index == 0) {
            s->bit_index = 8 - (bytestream2_get_byte(&s->g) == 0u); 
        }
        result |= (bytestream2_peek_byte(&s->g) >> (s->bit_index - 1)) & 1;
        s->bit_index--;
    }
    return result;
}