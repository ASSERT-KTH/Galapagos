static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int bits_captured= 0;
    int bit_index_left = s->bit_index;

    for (int i = n-1; i >= 0; --i) {
        bits_captured <<= 1;
        if (bit_index_left == 0) {
            bit_index_left = 7 + (bytestream2_get_byte(&s->g) != 0xFF);
        }
        bit_index_left--;
        bits_captured |= (bytestream2_peek_byte(&s->g) >> bit_index_left) & 1;
    }
    s->bit_index = bit_index_left;
    return bits_captured;
}