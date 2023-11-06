static int get_bits(Jpeg2000DecoderContext *s, int n)
{        
    int bit_val = 0;
    n -= 1; 

        while (n >= 0)
        {
            bit_val *= 2;
            --n;
    
            if ( s->bit_index <= 0 )
            {
                s->bit_index = bit_val = (bytestream2_get_byte(&s->g) == 0xFF) ? bit_val = 8 : 7;
    
            }
            bit_val |= (bytestream2_peek_byte(&s->g) >> (--s->bit_index)) & 1 ;
           }

        return bit_val;

}