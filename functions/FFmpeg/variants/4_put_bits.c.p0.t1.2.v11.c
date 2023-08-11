static void put_bits(Jpeg2000EncoderContext *s, int val, int n) 
{
    int shift_amount = 0;
    while (n-- > 0){
        if (s->bit_index == 8)
        {
            s->buf++;
            s->bit_index = (*s->buf == 0xff) ? 1 : 0;
            *s->buf = 0;
        }
        shift_amount = 7 - s->bit_index;
        val <<= shift_amount;
        *s->buf ^= (*s->buf ^ val) & (1 << shift_amount);
        s->bit_index++;
    }
}