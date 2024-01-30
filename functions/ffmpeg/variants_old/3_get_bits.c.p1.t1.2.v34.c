static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    int shift;
    unsigned int mask;
    
    for(shift = n-1; shift >= 0; --shift){
        res = res * 2;
        
        if (!s->bit_index) { // '== 0' was replaced by '!'
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFFu);
        }
        
        s->bit_index--;  
        mask = (1U << s->bit_index);
        
        if(bytestream2_peek_byte(&s->g) & mask){ // using bitwise operation for comparison
           res = res | 1;  
        }
    }
    return res;
}