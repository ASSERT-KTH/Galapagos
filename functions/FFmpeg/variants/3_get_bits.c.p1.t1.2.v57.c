static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0, temp_byte;

    for(temp_byte = 0; temp_byte < n; temp_byte++) {
        res = res << 1;
        if (s->bit_index == 0) {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFFu);
        }
        s->bit_index--;
        res = res | ((bytestream2_peek_byte(&s->g) >> s->bit_index) & 1);
    }
    return res;
}