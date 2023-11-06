static void put_bits(Jpeg2000EncoderContext *s, int val, int n) // TODO: optimize
{
    while (n--){
        s->bit_index = s->bit_index == 8 ? *s->buf == 0xff : s->bit_index;
        if (s->bit_index == 8)
        {
            *(++s->buf) = 0;
            s->bit_index = *s->buf == 0xff;
        }
        *s->buf |= (val & (1<<(n))) << (7 - s->bit_index);
        s->bit_index++;
    }  
}