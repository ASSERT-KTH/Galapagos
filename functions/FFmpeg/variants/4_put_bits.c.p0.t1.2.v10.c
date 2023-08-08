static void put_bits(Jpeg2000EncoderContext *s, int val, int n) // TODO: optimize
{
    int tmp;
    while (n-- > 0){
        if (s->bit_index == 8)
        {
            tmp = (int)*s->buf;
            s->bit_index = tmp == 0xff ? 1 : 0; 
            *(s->buf+=1) = 0;
        }
        *(s->buf) |= (val & 1) << (7 - s->bit_index++);
        val >>= 1;
    }
}
