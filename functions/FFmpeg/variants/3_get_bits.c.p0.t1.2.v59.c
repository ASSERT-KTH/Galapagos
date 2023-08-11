static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    int temp_bit_index = s->bit_index;
    uint8_t temp_byte = bytestream2_get_byte(&s->g);

    for (int i = n - 1; i >= 0; i--) {
        if (temp_bit_index == 0) {
            temp_bit_index = 7 + ((temp_byte = bytestream2_get_byte(&s->g)) != 0xFF);
        }
        temp_bit_index--;
        res |= ((temp_byte >> temp_bit_index) & 1) << i;
    }
    s->bit_index = temp_bit_index;

    return res;
}