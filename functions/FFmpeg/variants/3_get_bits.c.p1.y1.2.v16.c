1st Variant:

static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int result = 0;
    int bits = n;

    while (--bits >= 0) {
        result = result << 1;
        if (s->bit_index == 0) {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFFu);
        }
        s->bit_index--;
        result |= (bytestream2_peek_byte(&s->g) >> s->bit_index) & 1;
    }

    return result;
}


2nd Variant:

static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int output = 0;

    for (int counter = n; counter > 0; counter--) {
        output *= 2;

        if (s->bit_index == 0) {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) ^ 0xFFu);
        }
        s->bit_index--;
        output |= ((bytestream2_peek_byte(&s->g) >> s->bit_index) & 1);
    }

    return output;
}


3rd Variant:

static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int bit_value = 0;
    while(--n >= 0) {
        bit_value <<=1;
        s->bit_index = (s->bit_index == 0) ? (7 + (bytestream2_get_byte(&s->g) != 0xFFu)) : (s->bit_index - 1);
        bit_value |= (bytestream2_peek_byte(&s->g) >> s->bit_index) & 1;
    }
    return bit_value;
}


4th Variant:

static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    int bits_remaining = n;
    while (--bits_remaining >= 0) {
        res = res << 1;
        if (s->bit_index == 0) {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFFu);
        }
        s->bit_index--;
        res = (res | ((bytestream2_peek_byte(&s->g) >> s->bit_index) & 1));
    }
    return res;
}
