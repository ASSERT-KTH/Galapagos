static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int bit_index, res = 0;
    unsigned int byte = 0;

    while(n--) {
        if (!s->bit_index) {
            byte = bytestream2_get_byte(&s->g);
            s->bit_index = (byte == 0xFFu) ? 7 : 8;
        }

        bit_index = --s->bit_index;
        byte = bytestream2_peek_byte(&s->g);
        
        res = (res << 1) | ((byte >> bit_index) & 1);
    }

    return res;
}