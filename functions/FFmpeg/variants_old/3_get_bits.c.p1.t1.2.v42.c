static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    unsigned char currentByte = 0;
    int res = 0;

    while (n-- > 0) {
        if (s->bit_index == 0) {
            currentByte = bytestream2_get_byte(&s->g);
            s->bit_index = ((currentByte != 0xFFu) ? 8 : 7);
        }
        s->bit_index--;
        res = (res << 1) | ((bytestream2_peek_byte(&s->g) >> s->bit_index) & 1);
    }
    return res;
}