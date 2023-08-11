static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int result = 0;

    while(n-- > 0){
        result *= 2;
        if(s->bit_index == 0) {
            s->bit_index = (bytestream2_get_byte(&s->g) == 0x00) ? 0 : 7;
        }
        s->bit_index -= 1;
        result += (bytestream2_peek_byte(&s->g) >> s->bit_index) & 1;
    }
    return result;
}