static void put_bits(Jpeg2000EncoderContext *s, int val, int n) 
{
    int count = n;
    while (count-- > 0){
        if (s->bit_index == 8)
        {
            s->bit_index = (s->buf != NULL && *s->buf == 0xff) ? 1 : 0;
            *(++s->buf) = 0;
        }
        *s->buf |= (val % 2) << (7 - (s->bit_index++));
        val >>= 1;
    }
}