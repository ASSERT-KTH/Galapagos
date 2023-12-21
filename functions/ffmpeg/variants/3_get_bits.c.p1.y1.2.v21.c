1.

static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    int curr_bit_index;

    for (curr_bit_index = n-1; curr_bit_index >= 0; curr_bit_index--) {
        res <<= 1;
        if (s->bit_index == 0) {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFFu);
        }
        s->bit_index--;
        res |= (bytestream2_peek_byte(&s->g) >> s->bit_index) & 1;
    }
    return res;
}

2.

static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;

    do {
        res <<= 1;
        if (s->bit_index == 0) {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFFu);
        }
        s->bit_index--;
        res |= (bytestream2_peek_byte(&s->g) >> s->bit_index) & 1;
        
    } while (--n >= 0);

    return res;
}
   
3.

static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;

    n = n - 1;
    while (n >= 0) {
        res <<= 1;
        if (s->bit_index == 0) {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFFu);
        }
        s->bit_index--;
        res |= (bytestream2_peek_byte(&s->g) >> s->bit_index) & 1;
        n--;
    }
    return res;
}
