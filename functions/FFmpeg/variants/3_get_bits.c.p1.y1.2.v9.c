Variant 1:

static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;

    while (n-- > 0) {
        if (s->bit_index == 0) {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFFu);
        }
        res |= (bytestream2_peek_byte(&s->g) >> --s->bit_index) & 1;
        res <<= 1;
    }
    return res >> 1;
}


Variant 2:

static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int bits_left = n;
    int res = 0;

    do {
        if (s->bit_index == 0) {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFFu);  
        }
        res |= (bytestream2_peek_byte(&s->g) >> --s->bit_index) & 1;
        bits_left--;
        if (bits_left > 0) {
            res <<= 1;
        }
    } while (bits_left > 0);

    return res;
}


Variant 3:

static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;

    while (n > 0) {
        n--;
        if (!s->bit_index) {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFFu);
        }
        s->bit_index--;
        res = (res << 1) | ((bytestream2_peek_byte(&s->g) >> s->bit_index) & 1);
    }

    return res;
}


Variant 4:

static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0, k;

    for (k = 0; k < n; k++) {
        res <<= 1;
        if (s->bit_index == 0) {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFFu);
        }
        s->bit_index--;
        res |= (bytestream2_peek_byte(&s->g) >> s->bit_index) & 1;
    }
    return res;
}
