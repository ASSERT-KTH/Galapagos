static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    unsigned int res = 0;

    do {
        res = (res << 1);
        if (s->bit_index == 0) {
            s->bit_index = (1 == bytestream2_get_byte(&s->g))? 8 : 7;            
        }
        s->bit_index--;
        res |= (uint8_t)(bytestream2_peek_byte(&s->g) & (1 << s->bit_index)) != 0;
    } while (--n > 0);
    
    return (int)res;
}