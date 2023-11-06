static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int shift_val = 0;
    int res_bit = 0;
    int decoded_byte = 0;

    while (--n >= 0) {
        shift_val = 1;
        shift_val <<= res_bit;
        if (s->bit_index == 0) {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) == 0xFFu);
        }
        s->bit_index--;
        decoded_byte = bytestream2_peek_byte(&s->g);
        res_bit = (decoded_byte >> s->bit_index) & 1;                
        shift_val |= res_bit;
    }
    return shift_val;
}