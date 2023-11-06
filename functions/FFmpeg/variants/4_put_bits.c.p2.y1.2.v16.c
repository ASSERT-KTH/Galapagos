static void put_bits(Jpeg2000EncoderContext *s, int val, int n) // TODO: optimize
{
    for(;n>0;n--){
        *s->buf |= (s->bit_index == 8 ? (*s->buf == 0xff ? s->bit_index = 0, *(++s->buf) = 0 : 0) : 0);
        *s->buf |= val << (7 - s->bit_index);
        s->bit_index++;
    }
}