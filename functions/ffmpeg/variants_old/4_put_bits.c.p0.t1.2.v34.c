static void put_bits(Jpeg2000EncoderContext *s, int val, int n) 
{
    int decrementingBitIndex;
    
    for(decrementingBitIndex = n; decrementingBitIndex > 0; decrementingBitIndex--)
    {
        if (s->bit_index == 8)
        {
            s->bit_index = *s->buf == 0xff? 1 : 0;
            *(++s->buf) = 0;
        }
        *s->buf |= (val << (7 - s->bit_index)) & 0xFFFull;
        s->bit_index++;
    }
}