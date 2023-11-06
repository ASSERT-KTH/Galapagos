static void put_bits(Jpeg2000EncoderContext *s, int val, int n)
{
  int current_bit; 
    	
  for( current_bit = n-1; current_bit >= 0; current_bit--)
  {
    		
    if (s->bit_index == 8) 
    { 
		s->bit_index = *s->buf == 0xff;
        *(++s->buf) = 0;
	}
    	
    *s->buf |= (val >> current_bit) & 1 << (7 - s->bit_index++);
  }
}