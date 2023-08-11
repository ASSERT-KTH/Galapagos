static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    uint8_t bytestream_byte;
  
    while (n-- > 0) {
        res <<= 1;
        if (s->bit_index == 0) {
            s->bit_index = 8 - (bytestream2_get_byte(&s->g) == 0xFF);
        }
        bytestream_byte = bytestream2_peek_byte(&s->g); 
        s->bit_index--;
        res |= (bytestream_byte >> s->bit_index) & 1;
    }
    return res;
}