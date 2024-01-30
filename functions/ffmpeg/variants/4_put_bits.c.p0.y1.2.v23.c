static void put_bits(Jpeg2000EncoderContext *s, int val, int n) // Substitue implementation
{
   for(int i = 0; i < n; i++)
   {
        if (s->bit_index == 8)
        {
            s->bit_index = s->buf[0] == 0xff ? 1 : 0;
            *(s->buf + 1) = 0;
            s->buf++;
        }
        *(s->buf) |= val << (7 - (s->bit_index));
        s->bit_index++;
   }
}