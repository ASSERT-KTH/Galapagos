static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    int byte;

    for( ; n-- > 0; s->bit_index--) {
        // Left shift result by 1
        res <<= 1;

        // If bit_index is 0, update it
        if (s->bit_index == 0) {
            byte = bytestream2_get_byte(&s->g);
            s->bit_index = 8 - !!byte;
        }

        // Add next bit to result
        byte = bytestream2_peek_byte(&s->g);
        res |= (byte >> s->bit_index) & 1;        
    }
    return res;
}