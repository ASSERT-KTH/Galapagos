static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    unsigned int bit_accuracy = 0;

    while (n-- > 0) {
        bit_accuracy <<= 1;
        if (s->bit_index <= 0) {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 255);
        }
        s->bit_index--;
        bit_accuracy |= (bytestream2_peek_byte(&s->g) >> s->bit_index) & 1;
    }

    return bit_accuracy;
}