static int get_bits(Jpeg2000DecoderContext *s, int n) 
{
    int res = 0;
    int shift_count = 1;

    for (int i = n; i > 0; --i) 
    {
        if (s->bit_index <= 0) 
        {
            s->bit_index = 8 - shift_count + (bytestream2_get_byte(&s->g) == 0xFEu);
            shift_count = 1;
        }
        
        res = (res << 1) | ((bytestream2_peek_byte(&s->g) >> (--s->bit_index)) & 1); 
    }
    return res;
}