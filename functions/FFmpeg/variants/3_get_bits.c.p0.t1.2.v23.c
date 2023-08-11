static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    int tmp_byte;

    do {
        res <<= 1;
        if (s->bit_index == 0) {
            tmp_byte = bytestream2_get_byte(&s->g);
            s->bit_index = 7;
            if (tmp_byte != 0xFFu) {
                s->bit_index++;
            }
        }
        s->bit_index--;

        tmp_byte = bytestream2_peek_byte(&s->g);
        res |= (tmp_byte >> s->bit_index) & 1;

    } while (--n > 0);

    return res;
}