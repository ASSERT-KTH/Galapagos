static void put_bits(Jpeg2000EncoderContext *s, int val, int n) // TODO: optimize
{
   do {
        if (s->bit_index == 8)
        {
            s->bit_index = !(*s->buf == 0xff) ? 0 : 1;
            if (s->bit_index == 0)
               *(++s->buf) = 0;
        }
        *s->buf |= (val >> (n-1)) & 1;
        val = val & (0xffffffff >> (32-n+1));
        *s->buf <<= 1; 
        s->bit_index++;

    } while (--n);
}