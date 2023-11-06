1. Change of loop control logic

static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    int temp = n;

    for(int i = 0; i < temp; i++) {
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


2. Use ternary operation for if

static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;

    while (--n >= 0) {
        res <<= 1;
        s->bit_index = (s->bit_index == 0) ? (7 + (bytestream2_get_byte(&s->g) != 0xFFu)) : s->bit_index--;
        res |= (bytestream2_peek_byte(&s->g) >> s->bit_index) & 1;
    }
    return res;
}


3. Change res bitwise shift and set to one lines of code:

static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;

    while (--n >= 0) {
        if (s->bit_index == 0) {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFFu);
        }
        s->bit_index--;
        res = (res << 1) | ((bytestream2_peek_byte(&s->g) >> s->bit_index) & 1);
    }
    return res;
}


4. Convert "if" conditions into one liner

static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    while (--n >= 0) {
        res <<= 1;
        s->bit_index = s->bit_index ? s->bit_index-1 : 7 + (bytestream2_get_byte(&s->g) != 0xFFu);
        res |= (bytestream2_peek_byte(&s->g) >> s->bit_index) & 1;
    }
    return res;
}
