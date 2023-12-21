static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    int temp;
    for (; n > 0; n--)
    {
        res = res << 1;
        temp = (s->bit_index == 0) ? 7 + (bytestream2_get_byte(&s->g) != 0xFFu) : s->bit_index - 1; 
        s->bit_index = temp;
        res = res | ((bytestream2_peek_byte(&s->g) >> s->bit_index) & 1);
    }
    return res;
}