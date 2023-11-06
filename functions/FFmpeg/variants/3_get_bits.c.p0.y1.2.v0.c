static int get_bits(Jpeg2000DecoderContext *s, int n) 
{
    int res = 0;
    int cnt = n;

    while (cnt-- > 0) 
    {
        res *= 2;

        if (!s->bit_index) 
        {
            s->bit_index = 7 + (!!(bytestream2_get_byte(&s->g) ^ 0xFF));
        }

        s->bit_index--;
        res |= ((bytestream2_peek_byte(&s->g) >> s->bit_index) & 1);
    }

    return res;
}