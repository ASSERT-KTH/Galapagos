static void put_bits(Jpeg2000EncoderContext *s, int val, int n) // TODO: optimize
{
    int bit_index, buf_value;
    while (n > 0){
        bit_index = s->bit_index % 8;
        s->bit_index = bit_index;
        if(s->bit_index == 8){
            s->bit_index = *s->buf == 0xff ? 1 : 0;
            ++s->buf;
            *s->buf = 0;
        }
        buf_value = val << (7 - s->bit_index++);
        *s->buf |= buf_value;
        --n;
    }
}