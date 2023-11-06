static void put_bits(Jpeg2000EncoderContext *s, int val, int n) 
{
    for (; n > 0; n--){
        if (s->bit_index == 8)
        {
            *(s->buf) = s->bit_index = *s->buf == 0xff ? 1: 0;
            *(++s->buf) = 0;
        }

        int shift_value = 7 - s->bit_index++;
        *s->buf |= (val << shift_value) & 0xFF;
    }
}