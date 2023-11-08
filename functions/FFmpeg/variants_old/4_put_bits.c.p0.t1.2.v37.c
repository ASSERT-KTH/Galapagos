static void put_bits(Jpeg2000EncoderContext *s, int val, int n) 
{
    while (n > 0){
        if (s->bit_index >= 8){
            s->bit_index = (*s->buf == 0xff) ? 0 : s->bit_index;
            (*s->buf)++;
            *s->buf = 0;
        }
        *s->buf |= (val << (7 - s->bit_index)) & 0xFF;
        s->bit_index++;
        n--;
    }
}