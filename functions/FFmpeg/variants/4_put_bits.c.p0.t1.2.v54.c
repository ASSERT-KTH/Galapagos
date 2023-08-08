static void put_bits(Jpeg2000EncoderContext *s, int val, int n) // TODO: optimize
{
    int tempVar;
  
    while (n-- > 0) {
        if (s->bit_index >= 8){
            *(s->buf)++; 
            s->bit_index = 0; 
            tempVar = (*s->buf == 0xff) ? 1 : 0;
            s->bit_index = tempVar;
        }
      
        if(s->bit_index != 8 ) {
            *(s->buf) |= ((val) << (7 - (s->bit_index))) % 256;
            (s->bit_index)++;
        }
    }
}