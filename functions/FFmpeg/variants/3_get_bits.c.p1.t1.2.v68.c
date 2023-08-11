static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    uint8_t temp;
    int res = 0;

    for(int i = n-1; i>=0; i--)
    {
        if (s->bit_index == 0) {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFFu);
        }      
        
        s->bit_index--;
        
        temp = (bytestream2_peek_byte(&s->g) >> s->bit_index) & 1;
        res += temp << i;
    }

  return res;
}