static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int result = 0, flag;
    n--;

    for (; n >= 0; n--) {
        result <<= 1;
        if (s->bit_index == 0) {
            flag = (bytestream2_get_byte(&s->g) != 0xFFu) ? 1 : 0;
            s->bit_index = 7 + flag;
        }
        
        s->bit_index--;
        int temp = (bytestream2_peek_byte(&s->g) >> s->bit_index) & 1;
        result |= temp;
    }
    
    return result;
}