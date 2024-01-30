static void put_bits(Jpeg2000EncoderContext *s, int val, int n) 
{
    int shiftedVal;
    while(n > 0)
    {
        if(s->bit_index == 8)
        {
            s->bit_index = (0xff == *s->buf ? 1 : 0);
            s->buf ++;
            *s->buf = 0;
        }
        shiftedVal = val % 2;
        shiftedVal = shiftedVal << (7 - s->bit_index++);
        *s->buf |= shiftedVal;
        val = val >> 1;
        n--;
    }
}