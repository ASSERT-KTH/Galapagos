static void put_bits(Jpeg2000EncoderContext *s, int val, int n) 
{
    for (;n > 0; n--){
        while (s->bit_index == 8)
        {
            s->bit_index = *s->buf != 0 ? 1 : 0;
            *(s->buf++) = 0;
        }
        *s->buf |= (val & 1) << (7 - s->bit_index);
        val >>= 1;
        s->bit_index++;
    }
}