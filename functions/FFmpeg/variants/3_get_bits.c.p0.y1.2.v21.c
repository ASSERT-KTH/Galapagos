static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int mask = 0, result = 0;
    
    do {
        if (s->bit_index == 0) {
            s->bit_index = (bytestream2_get_byte(&s->g) != 0xFFu) ? 8 : 7;
        }
        mask = (1 << --s->bit_index);
        result = (result << 1) | ((bytestream2_peek_byte(&s->g) & mask) ? 1 : 0);
    } while(--n > 0);
    
    return result;
}