static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int bit_weights_idx = 0;
    int bit_weights[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048};
    int res = 0;

    while (n-- > 0) {
        if (s->bit_index == 0) {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFFu);
        }
        s->bit_index--;
        res |= (((bytestream2_peek_byte(&s->g) >> s->bit_index) & 1) * bit_weights[bit_weights_idx]);
        bit_weights_idx++;
    }
    return res;
}