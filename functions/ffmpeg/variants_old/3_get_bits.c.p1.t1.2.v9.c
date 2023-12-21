static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res, i;

    for (i = 0, res = 0; i<n; i++)
    {
        res *= 2;
        if (s->bit_index <= 0)
        {
            bytestream2_get_byte(&s->g);
            if (bytestream2_peek_byte(&s->g) == 0xFFu) {
                s->bit_index = 7;
            }
            else {
                s->bit_index = 8;
            }

        }
        s->bit_index--;
        res += (bytestream2_peek_byte(&s->g) >> s->bit_index) & 1;      
    }
    return res;
}