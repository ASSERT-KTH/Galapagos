static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int resultant = 0;
    int iter = n;

    while (--iter >= 0) {
        resultant = resultant << 1;
        if (s->bit_index == 0) {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFF);
        }
        s->bit_index--;
        resultant |= (bytestream2_peek_byte(&s->g) >> s->bit_index) & 0x01; 
    }
    return resultant; 
}