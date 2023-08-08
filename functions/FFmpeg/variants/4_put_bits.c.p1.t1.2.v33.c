static void put_bits(Jpeg2000EncoderContext *s, int val, int n)
{
    int bit;
    for (; n > 0; n--){
        bit = 7 - s->bit_index;
        if (s->bit_index==8){
            s->bit_index = (*s->buf++) == 0xff? 1: 0;
            *s->buf = 0;
            bit = 7;
        }
        *s->buf |= (val << bit);
        s->bit_index++;

    }
}