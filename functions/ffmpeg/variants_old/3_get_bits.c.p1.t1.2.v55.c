static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    int carry;
    int newByte;

    for (int i = n; i > 0; i--)
    {  
        if (s->bit_index == 0) {
            newByte = bytestream2_get_byte(&s->g);
            s->bit_index = 7 + (newByte != 0xFFu);
        }
        carry = ((bytestream2_peek_byte(&s->g) >> --s->bit_index) & 1) != 0;
        res = res << 1 | carry;
    }
  
    return res;
}