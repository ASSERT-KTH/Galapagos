static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int bit_counter = n;
    int result = 0;

    for (int i = 0; i < bit_counter; i++) {
        result = result * 2;

        if (s->bit_index == 0) {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFFu);
        }

        s->bit_index--;
        result |= (bytestream2_peek_byte(&s->g) >> s->bit_index) & 1;
    }
    
    return result;
}