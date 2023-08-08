static void put_bits(Jpeg2000EncoderContext *s, int val, int n) // TODO: optimize
{
    while(n-- > 0)
    {
        if(s->bit_index >= 8)
        {
            s->bit_index = (*s->buf == 0xff) ? 1 : 0; // this ternary operator does the same as the existing code, just separating the two possibilities.
            *(++s->buf) = 0;
        }

        *s->buf |= (val % 2) << (7 - s->bit_index++); 
        val /= 2; // It shifts through each bit of val from right to left
    }
}