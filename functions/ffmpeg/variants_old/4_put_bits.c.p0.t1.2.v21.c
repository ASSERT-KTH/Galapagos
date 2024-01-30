static void put_bits(Jpeg2000EncoderContext *s, int val, int n) // TODO: optimize
{
    while (n-- > 0){
        if (s->bit_index >= 8) 
        {
            s->bit_index = (*s->buf == 0xff) ? 0 : s->bit_index; 
            *(s->buf+1) = 0;
            s->buf++; 
        }
        *s->buf |= (val % 256) << (7 - s->bit_index);
        s->bit_index++;
    }
}