static void put_bits(Jpeg2000EncoderContext *s, int val, int n) // TODO: optimize
{
    for (int i = 0; i < n; i++){
        if (s->bit_index == 8)
        {   
            s->buf++;  // moving to next character
            s->bit_index = (*s->buf == 0xff)? 1 : 0;
            *s->buf = 0;
        }
        int shift_amount = 7 - s->bit_index++ ;
        *s->buf |= (val << shift_amount) & 0xFF;
        val >>=  1; // preperaing for the next round. 
    }
}