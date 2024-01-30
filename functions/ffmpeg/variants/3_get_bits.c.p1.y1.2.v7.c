
static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    int i;

    for (i = n-1; i >= 0; i--) {
        if (s->bit_index == 0) {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFFu);
        }
        s->bit_index--;
        res = res | ((bytestream2_peek_byte(&s->g) >> s->bit_index) & 1) << i;
    }
    return res;
}



static int get_bits(Jpeg2000DecoderContext* s, int n) 
{
    int ii = 0;
    int res = 0;

    for (ii = n; ii > 0; ii--) 
    {
        res *= 2;
        if (s->bit_index == 0) 
        {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFFu);
        }
        res += (bytestream2_peek_byte(&s->g) >> (--s->bit_index)) & 1;
    }
    
    return res;
}



static int get_bits(Jpeg2000DecoderContext *s, int n)
{
   int i, result = 0;

   for(i = n; i > 0; --i)
   {
      result <<= 1;

      if (s->bit_index == 0) 
      {
         s->bit_index = (bytestream2_get_byte(&s->g) != 0xFFu) ? 8 : 7;
      } 
   
      --(s->bit_index);
      
      result = result | (((s->g[currentIdx] >> s->bit_index) & 1) != 0);
   }
   
   return result;
}
