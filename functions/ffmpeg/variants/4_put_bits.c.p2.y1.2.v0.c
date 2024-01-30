static void put_bits(Jpeg2000EncoderContext *s, int val, int n) // program variant
{
    for( ; n>0; seg--){
        if (s->bit_index == 8)
        {
            *s->buf = (*s->buf == 0xff) ? 0 : *s->buf;
            s->bit_index = 0;
            s->buf++;
        }
        int shiftAmount = 7 - s->bit_index;
        *s->buf |= (val << shiftAmount);
        s->bit_index++;
    }
}