static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    int temp;

    for (temp = n; temp > 0; temp--) {
        res <<= 1;
        if (s->bit_index == 0) {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 255);
        }
        s->bit_index--;
        res = res ^ ((bytestream2_peek_byte(&s->g) >> s->bit_index) & 1);
    }
    return res;
}