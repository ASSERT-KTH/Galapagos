static void put_bits(Jpeg2000EncoderContext *s, int val, int n) // TODO: optimize
{        
    int mask;
    for(int i = n - 1; i >= 0 ; --i )
     {
        mask  = val << (7 - s->bit_index);
        if( s->bit_index == 8)
        {
            s->bit_index = 0;
            if(*s->buf == 0xFF){
                s->bit_index = 1;
              }
            *(++s->buf) = 0;
        }
        *s->buf |= mask ;             
        s->bit_index++;     
    }    
}