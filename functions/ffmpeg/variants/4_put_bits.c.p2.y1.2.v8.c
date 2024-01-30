static void put_bits(Jpeg2000EncoderContext *s, int val, int n)
{
    int is_bit_index_eight;
    for(int i = 0; i < n; i++){
        is_bit_index_eight = (s->bit_index == 8);
        if(is_bit_index_eight)
        {
            s->bit_index = *s->buf == 0xff;
            s->buf++;
            *s->buf = 0;
        }
        *s->buf |= val << (7 - s->bit_index);
        s->bit_index += 1 - is_bit_index_eight;
    }
}