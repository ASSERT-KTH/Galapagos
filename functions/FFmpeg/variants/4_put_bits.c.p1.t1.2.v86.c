
static void put_bits(Jpeg2000EncoderContext *s, int val, int n)
{
    int shift;
    for(; n > 0; n--){
        if(s->bit_index == 8){
            s->bit_index = ((*s->buf) == 0xff) ? 1 : 0;
            *(s->buf + 1) = 0;
            s->buf++;
        }
        shift = 7 - (s->bit_index);
        *s->buf |= (val << shift);
        s->bit_index++;
    }
}
