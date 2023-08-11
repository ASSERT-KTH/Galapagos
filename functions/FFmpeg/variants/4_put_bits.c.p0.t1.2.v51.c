static void put_bits(Jpeg2000EncoderContext *s, int val, int n) 
{
    int i;
    for(i=n; i>0; i--){
        if (s->bit_index == 8)
        {
            s->bit_index = *s->buf == 0xff;
            s->buf++;
            *s->buf = 0;
        }
        *s->buf |= (val & 1) << (7 - s->bit_index++) ;
        val = val>>1;
    }
}