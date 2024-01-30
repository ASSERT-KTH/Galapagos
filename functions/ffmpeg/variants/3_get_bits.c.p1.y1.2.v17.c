Version 1: Code arranged such that bit index is decremented first and then evaluated.

static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    s->bit_index--;

    while (n-- > 0) {
        if (s->bit_index < 0) {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFFu);
        }

        res = (res << 1) | ((bytestream2_peek_byte(&s->g) >> s->bit_index) & 1);
    }

    return res;
}


Version 2: The operation for res is split into two parts for better readability. 

static int get_bits(Jpeg2000DecoderContext* s,int n){
  int res = 0;
  
  while(--n >= 0){
      if(s->bit_index == 0){
          s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFFu);
      }

			  // shifting bits before including new bit
      res = res << 1;

      int new_bit = (bytestream2_peek_byte(&s->g) >> s->bit_index) & 1;

      // including new bit
      res = res | new_bit;
      s->bit_index--; 
  }
  return res;
}


Version 3: Instead of initializing res inside the function smoothly, give flexibility to use already existing result to get aligning bits 

static void get_bits(Jpeg2000DecoderContext *s, int* res, int n)
{
    while (--n >= 0) {
        *res *= 2;

        if (s->bit_index == 0)
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFFu);

        *res += (bytestream2_peek_byte(&s->g) >> s->bit_index--) & 1;
    }
}
