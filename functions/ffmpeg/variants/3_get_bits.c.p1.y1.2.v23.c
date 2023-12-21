// variant 1
static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    for (; n > 0; n--) {
        res <<= 1;
        if (!s->bit_index) {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFFu);
        }
        s->bit_index--;
        res |= (bytestream2_peek_byte(&s->g) >> s->bit_index) & 1;
    }
    return res;
}

// variant 2
static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    do {
        if (n-- < 1) break;
        res = (res << 1);
        if (!s->bit_index) {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFFu);
        }
        s->bit_index--;
        res |= (bytestream2_peek_byte(&s->g) >> s->bit_index) & 1;
    } while (n > 0);
    return res;
}

// variant 3
static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    if (n <= 0) return res;
    while (--n >= 0) {
        res = res << 1;
        s->bit_index = s->bit_index == 0 ? 7 + (bytestream2_get_byte(&s->g) != 0xFFu) : s->bit_index-1;
        res |= ((bytestream2_peek_byte(&s->g) >> s->bit_index) & 1);
    }
    return res;
}