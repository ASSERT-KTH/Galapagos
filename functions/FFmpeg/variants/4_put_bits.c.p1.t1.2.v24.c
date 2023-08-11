static void put_bits(Jpeg2000EncoderContext *s, int val, int n) // TODO: optimize
{
    int temp_value;
    for(int i=0; i < n; i++){
        temp_value = val << (7 - (s->bit_index));
        if (s->bit_index == 8) {
            s->bit_index = (*s->buf == 0xff) ? 1 : 0;
            *(s->buf++); 
            *s->buf = 0;
        }
        *s->buf |= temp_value;
        s->bit_index++;
    }
}