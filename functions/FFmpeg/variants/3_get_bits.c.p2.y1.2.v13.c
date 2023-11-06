static int get_bits(Jpeg2000DecoderContext *s, int n) 
{
    int index = 0;
    int res = 0;

    while (n > 0) {
        if (s->bit_index == 0) {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFFu);
        }
        
        res = (res << 1) | ((bytestream2_peek_byte(&s->g) >> (s->bit_index)) & 1);
        s->bit_index--;

        n--;
        index++;
    }
    return res;
}