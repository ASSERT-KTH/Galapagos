static int get_bits(Jpeg2000DecoderContext *s, int n)
{
   int res = 0, c;

   for (int i = n; i > 0 ; --i) {
       res <<= 1;
       if(s->bit_index == 0){
           c = bytestream2_get_byte(&s->g);
           s->bit_index = c != 0xFFu ? 8 : 7;
       }
       --s->bit_index;
       res |= (bytestream2_peek_byte(&s->g) >> s->bit_index) & 1;
   }
   return res;
}