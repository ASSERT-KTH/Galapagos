static void put_bits(Jpeg2000EncoderContext *s, int val, int n) // TODO: optimize
{
    for(;n>0;n--){
        ternaryBitIndexCheck(s);
        *s->buf |= val << (7 - s->bit_index++);
    }
}

inline void ternaryBitIndexCheck(Jpeg2000EncoderContext *s) {
    if(s->bit_index == 8) {
        s->bit_index = *(s->buf) == 0xff ? 1 : 0;
        *(++s->buf) = 0;
    }
}