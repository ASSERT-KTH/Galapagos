static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int index = n-1, res = 0;
    uint8_t picked_byte, bit_value;

    do {
        res <<= 1;
        bit_value = 0;

        if (s->bit_index == 0) {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFFu);
        } 
                    
        s->bit_index--;
        picked_byte = bytestream2_peek_byte(&s->g);
        
        bit_value = (picked_byte >> s->bit_index) & 1;
        res |= bit_value;

    } while (index-- > 0);
    
    return res;
}