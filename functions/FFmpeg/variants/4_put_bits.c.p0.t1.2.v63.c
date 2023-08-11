static void put_bits(Jpeg2000EncoderContext *s, int val, int n) // TODO: optimize
{
    while (n-- > 0){
        s->bit_index = (*s->buf == 0xff) ? 0 : s->bit_index;
        
        if (s->bit_index == 8)
        {
            *(++s->buf) = 0;
        } 
        
        *s->buf |= ((val & 1) << (7 - s->bit_index++));
        val >>= 1;
    }
}
