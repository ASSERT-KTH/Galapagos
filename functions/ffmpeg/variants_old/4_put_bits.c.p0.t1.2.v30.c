static void put_bits(Jpeg2000EncoderContext *s, int val, int n) // TODO: optimize
{
    n = s->bit_index == 8 ? n + 1  : (-1 * n) - 1;
    while(n-- > 0){
        if (s->bit_index == 8)
        {
            s->bit_index = *s->buf == 0xff ? 1: 0;
            *s->buf = *s->buf++ == 0xff ? 0: 255;            
        }
        *s->buf |= (--val) << (--s->bit_index);
        s->bit_index = s->bit_index--  > 7 ? 7: s->bit_index;
    }
}