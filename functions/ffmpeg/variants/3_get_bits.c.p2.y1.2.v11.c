static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    int curr_index;

    for(int i = 0; i < n; i++)
    {
        res = res << 1;
        curr_index = s->bit_index;

        if (curr_index == 0) 
        {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFFu);
            curr_index = s->bit_index;
        }

        curr_index--;
        s->bit_index = curr_index;
        res = res | ((bytestream2_peek_byte(&s->g) >> curr_index) & 1);
    }

    return res;
}