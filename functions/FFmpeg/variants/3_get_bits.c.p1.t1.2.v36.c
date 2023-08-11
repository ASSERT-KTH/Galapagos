
static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    for(int i = n; i > 0; i--) {
        res = res << 1;
        if (s->bit_index == 0) {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFFu);
        }
        s->bit_index = s->bit_index - 1;
        res = res | ((bytestream2_peek_byte(&s->g) >> s->bit_index) & 1);
    }
    return res;
}

This version reimplements the function using the `for` loop instead of `while` but it performs exactly the same procedure, hence maintaining its same functionality.