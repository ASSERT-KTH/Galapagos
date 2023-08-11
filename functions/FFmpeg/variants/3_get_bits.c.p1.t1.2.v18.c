static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    int shift_val;

    for( ; n > 0; n--){
        res = res << 1;

        if ( !s->bit_index ) {
            if(bytestream2_get_byte(&s->g)!= 0xFFu)
                s->bit_index = 8;
            else 
                s->bit_index = 7;  
        }
        shift_val = (bytestream2_peek_byte(&s->g) >> --s->bit_index);
        res = res | (shift_val & 1);
    }
    return res;
}