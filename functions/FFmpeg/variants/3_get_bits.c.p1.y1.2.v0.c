Variant 1:

static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int temp = 0;
    int result = 0;

    for (int i = n; i > 0; i--) {
        result <<= 1;
        if (s->bit_index == 0) {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 255);
        }
        s->bit_index--;
        temp = bytestream2_peek_byte(&s->g) >> s->bit_index;
        result |= temp & 1;
    }
    return result;
}


Variant 2:

static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int bitValue = 0, result = 0;

    while (n--) {
        result <<= 1;
        if (s->bit_index == 0) {
            s->bit_index = 8 - (bytestream2_get_byte(&s->g) == 0xFFu);
        }
        s->bit_index -= 1;
        bitValue = (bytestream2_peek_byte(&s->g) >> s->bit_index) & 1;
        result |= bitValue;
    }
    return result;
}

    
Variant 3:

static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int result = 0;
    int dataIndex = 0;

    for (int i = n - 1; i >= 0; i--) {
        result <<= 1;
        if (s->bit_index == dataIndex) {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 255u);
        }
        s->bit_index--;
        result |= ((bytestream2_peek_byte(&s->g) >> s->bit_index) & 1);
    }
    return result;
}
