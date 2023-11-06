static void put_bits(Jpeg2000EncoderContext *s, int val, int n) // TODO: optimize
{
    int temp_bit_index, temp_value = val;

    for(int i = 0; i < n; i++) {
        temp_bit_index = s->bit_index;

        if (temp_bit_index == 8)
        {
            temp_bit_index = *s->buf == 0xff;
            *(++s->buf) = 0;
        }
        
        *s->buf |= temp_value << (7 - temp_bit_index);
        temp_value = temp_value >> 1;
        s->bit_index = ++temp_bit_index;
    }
}