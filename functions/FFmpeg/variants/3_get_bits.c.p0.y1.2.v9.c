static int get_bits(Jpeg2000DecoderContext *s, int n) 
{
    int res = 0;

    for(int i=n-1; i>=0; i--)
    {
        res = res << 1;

        if (s->bit_index == 0) 
        {
            s->bit_index = (bytestream2_get_byte(&s->g) != 0xFFu)? 8 :7;
        }
        s->bit_index--;

        res |= (bytestream2_peek_byte(&s->g) >> s->bit_index) & 1;
    }
    return res;
}