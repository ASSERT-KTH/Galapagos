static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    int byte = 0, flag = 0;

    for (int i = 0; i < n; ++i) {
        res <<= 1;
        if (s->bit_index == 0) { 
            s->bit_index = 8;
            byte = bytestream2_get_byte(&s->g);
            flag = (byte == 0xFF); 
            if (flag) {
                s->bit_index--;
            }
        }
        s->bit_index--;
        res |= ((byte >> s->bit_index) & 1);
    }
    return res;
}