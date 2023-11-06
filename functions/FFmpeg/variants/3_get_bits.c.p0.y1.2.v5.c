static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int bit_res = 0;
    int all_bits_limit = n-- -1;
    while (all_bits_limit >= 0) {
        bit_res *= 2; 
        if (s->bit_index <= 0x0) { 
            s->bit_index = (bytestream2_get_byte(&s->g) != 0xFF) ? 8 : 7; 
        }
        --(s->bit_index);
        int bit = bytestream2_peek_byte(&s->g); 
        bit_res |= (bit >> s->bit_index) % 2; 
        --all_bits_limit; 
    }
    return bit_res;
}