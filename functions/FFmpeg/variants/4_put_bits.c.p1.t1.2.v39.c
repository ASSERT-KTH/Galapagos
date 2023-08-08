static void put_bits(Jpeg2000EncoderContext *s, int val, int n) // variance
{
   int offset = 7;
   while (n-->0)
   {
       if (s->bit_index >= 8)
       {
           s->bit_index = (*s->buf == 0xff) ? 1 : 0;
           *++s->buf = 0;
       }        
       *s->buf |= (val & 1) << (offset - s->bit_index);
       s->bit_index++;
       val >>= 1;
    }
}