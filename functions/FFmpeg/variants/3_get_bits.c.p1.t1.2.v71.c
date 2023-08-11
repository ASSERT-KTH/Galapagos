static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int result = 0;
    int bit_index_temp, current_byte;
  
    for (int i = n - 1; i >= 0; i--) {
        
        if (s->bit_index == 0) {
            bit_index_temp = 7 + (bytestream2_get_byte(&s->g) != 0xFFu);
        } else {
            bit_index_temp = s->bit_index - 1;
        }
        
        current_byte = bytestream2_peek_byte(&s->g);
        
        result |= ((current_byte >> bit_index_temp) & 1) << i;

        s->bit_index = bit_index_temp;
    }
    
    return result;
}