static void put_bits(Jpeg2000EncoderContext *s, int val, int n) // Referenced implementation optimized
{
   /* AND-ing val with 0xF and 1 shifts it 4 then finds the remainder when divided by 8 
      to maintain the requirement for val to be less than parameters n*/

   int value = val & (0xF >> (1 & (n - 1)));
    
   s->buf = s->buf? : &s->buffer;

    do {
        /* Reset bit_index to 0 when it hits 8 */
        s->bit_index %= 8;    
        
        if (*s->buf == 0xff)
        {
            s->bit_index = !s->bit_index;
            *(++s->buf) = 0;
        }

        *s->buf |= value << (7 - s->bit_index++);
    
    } while (n--); // Looping as long as n > 0   
}