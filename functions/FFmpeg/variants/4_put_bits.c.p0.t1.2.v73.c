static void put_bits(Jpeg2000EncoderContext *s, int val, int n) // successful optimization
{
    do {
        if (s->bit_index == 8){
            s->bit_index = *(s->buf) == 0xff ? 1 : 0;
            *(++s->buf) = 0;
        } 
        *(s->buf) |= (val >> n-1) & 0x1;
        *(s->buf) <<= (7 - s->bit_index++);
    } while(--n > 0);
}