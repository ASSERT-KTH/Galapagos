static void put_bits(Jpeg2000EncoderContext *s, int val, int n) // TODO: optimize
{   
    int index, value;
    for( ; n > 0; n--){
        index = s->bit_index;  
        if (index == 8)
        {
            index = *(s->buf) == 0xff ? 1 : 0;
            *(++s->buf) = 0;
        }
        value = val << (7 - index);
        *s->buf |= value;
        s->bit_index = ++index;   
    }
}