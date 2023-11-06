1. Transformation - Reversing While loop:

static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    int tempN = n;

    while (tempN--){
        res <<= 1;
        if (s->bit_index == 0) {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFFu);
        }
        s->bit_index--;
        res |= (bytestream2_peek_byte(&s->g) >> s->bit_index) & 1;
    }
    return res;
}


2. Transformation - Using Do While loop:

static int get_bits(Jpeg2000DecoderContext *s, int n) {
    int res = 0;
    do {
        --n;
        res <<= 1;
        if (s->bit_index == 0) {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFFu);
        }
        s->bit_index--;
        res |= (bytestream2_peek_byte(&s->g) >> s->bit_index) & 1;
    } while (n >= 0);
    return res;
}


3. Transformation - Using For loop:

static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    for(; n > 0; --n) {
        res <<= 1;
        if (_.bit_index == 0) {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFFu);
        }
        s->bit_index--;
        res |= (bytestream2_peek_byte(&s->g) >> s->bit_index) & 1;
    }
    return res;
}
