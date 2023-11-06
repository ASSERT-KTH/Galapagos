static void put_bits(Jpeg2000EncoderContext *s, int val, int n) 
{
    int shift_factor;
    for (; n > 0; n--){
        if (s->bit_index == 8)
        {
            *(s->buf) = (*s->buf == 0xff) ? (s->bit_index = 0, *(++s->buf)) : *s->buf;
            *s->buf = 0;
        }
        shift_factor = 7 - s->bit_index;
        *s->buf |= (val << shift_factor);
        s->bit_index += 1; 
    }
}