static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    int bit = 0;

    do {
        res = (res << 1);
        if (s->bit_index == 0) {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFF);
        }
        bit = (bytestream2_peek_byte(&s->g) >> --s->bit_index) & 1;
        res |= bit;
    } while(--n > 0);

    return res;
}