static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    int temp;

    for(int i=0; i<n; i++) {
        temp = (n - i - 1);
        res = res << 1;
        if (s->bit_index == 0) {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFFu);
        }
        s->bit_index--;
        res |= (bytestream2_peek_byte(&s->g) >> s->bit_index) & 1;
    }
    return res;
}