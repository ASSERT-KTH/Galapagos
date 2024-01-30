// Variant 1
static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0; // Initialize res.

     // As operands of bitshifting don't have to be initially zero, "_n" is tested first before right-bitshifting it into res. Afterwards "_n--" mentioned inside loop, then subtracted such "_n--", renders ok outside.
     do{    
        res *= 2;  // Left bitshifting multiplication by 2.
        if (s->bit_index == 0) 
        {
            s->bit_index = bytestream2_get_byte(&s->g) != 255 ? 7 : 8;    // Simplified non-arithmetic formula.
        }
        res |= ((bytestream2_peek_byte(&s->g) >> --s->bit_index) & 1);    // Using latest post-decrement resulates to shorter codes.
    } while (--n > 0);
    return res;
}


// Variant 2    
static int get_bits(Jpeg2000DecoderContext *s, int n) 
{
   int res = 0;
   for ( ; n > 0 ; n--) { 
        if(s->bit_index == 0) 
        {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFFu);
        }
        
        res = (res << 1)|((bytestream2_peek_byte(&s->g) >> --s->bit_index) & 1); 
        // Ignore bits which cant covered bytes inside "res" as adopted "res=(res<<1)|(newest bit from g)" replacing resule operations and assigning back to "res".                                                 
   }
   return res ;
}

// Variant 3
static int get_bits(Jpeg2000DecoderContext *s, int n)
{ 
   int res = 0;
   while(n-- > 0) 
   {
      if(!s->bit_index) 
      {
          s->bit_index = 8 - !(bytestream2_get_byte(&s->g) ^ 255);
          // bitwise Complement along shifts bit_index set from Jpeg2000
      }
      res= ( res << 1 )|((bytestream2_peek_byte(&s->g)>> --s->bit_index)&1);
      // Removed brackets for shorter codes based between compiled executions speed. Hereby compensate less architecture efficiency consequences encouraging coding minimal instructions resultant of similar.
   }
   return res;
}