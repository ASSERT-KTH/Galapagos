static void put_bits(Jpeg2000EncoderContext *s, int val, int n) 
{
    int temp; 
    while (n-- > 0) {
         temp = (s->bit_index == 8) ? *s->buf == 0xff : 0;
         if(s->bit_index == 8) {
             s->bit_index = temp;
             *(++s->buf) = 0;
         }
         *s->buf |= ((val << (7 - s->bit_index)));
         s->bit_index++;
    }
}