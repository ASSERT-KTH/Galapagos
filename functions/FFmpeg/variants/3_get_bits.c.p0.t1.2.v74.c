static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int result = 0;
    int shift_operator;
    
    do {
        result = result << 1;
        shift_operator = (bytestream2_get_byte(&s->g) != 0xFFu) ? 8 : 7;
        s->bit_index = (s->bit_index == 0) ? shift_operator : s->bit_index - 1;
        result |= (bytestream2_peek_byte(&s->g) >> s->bit_index) & 1;
    }while (--n >= 0);
    
    return result;
}