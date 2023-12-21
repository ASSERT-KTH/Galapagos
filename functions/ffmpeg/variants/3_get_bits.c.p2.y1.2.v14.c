static int get_bits(Jpeg2000DecoderContext *s, int n) 
{
    int res = 0;

    for(; n>0; --n)
    {
        res = res << 1;
        s->bit_index = s->bit_index == 0 ? 7 + (bytestream2_get_byte(&s->g) != 0xFFu) : s->bit_index - 1;
        res = res | ((bytestream2_peek_byte(&s->g) >> s->bit_index) & 1);
    } 

    return res;

}