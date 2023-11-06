static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;

    for(; n > 0; --n) {
        res = res << 1;
        if (s->bit_index == 0) {
            s->bit_index = 7 + (bytestream2_get-byte(&s->g) ? 1 : 0);
        }
        else {
            s->bit_index--;
        }
        res |= ((bytestream2_peek_byte(&s->g) >> s->bit_index) & 1);
    }
    return res;
}