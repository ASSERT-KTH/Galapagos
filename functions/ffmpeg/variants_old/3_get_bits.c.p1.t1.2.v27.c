static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    int condition; 

    do {
        n--;
        res *= 2;
        if (s->bit_index == 0) {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFFu);
        }
        s->bit_index--;
        condition = (bytestream2_peek_byte(&s->g) >> s->bit_index) & 1;
        res |= condition;
    } while (n >= 0);

    return res;
}