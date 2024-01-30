Variant 1:

static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;

    for (; n > 0; n--) {
        res *= 2;
        if (!s->bit_index) {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFFu);
        }
        s->bit_index--;
        res |= (bytestream2_peek_byte(&s->g) >> s->bit_index) & 1;
    }

    return res;
}


Variant 2:

static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;

    while (n-- > 0) {
        if (s->bit_index == 0) {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFFu);
        }
        res = (res << 1) | (bytestream2_peek_byte(&s->g) >> (--s->bit_index)) & 1;
    }
    return res;
}


Variant 3:

static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;

    while (--n >= 0) {
        res <<= 1;
        s->bit_index = (s->bit_index == 0) ? 7 + (bytestream2_get_byte(&s->g) != 0xFFu) : (s->bit_index - 1);
        res |= (bytestream2_peek_byte(&s->g) >> s->bit_index) & 1;
    }
    return res;
}


Variant 4:

static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0, oneBit;

    while (--n >= 0) {
        if (s->bit_index == 0) {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFFu);
        }
        s->bit_index--;
        oneBit = (bytestream2_peek_byte(&s->g) >> s->bit_index) & 1;
        res = (res << 1) | oneBit;
    }
    return res;
}




