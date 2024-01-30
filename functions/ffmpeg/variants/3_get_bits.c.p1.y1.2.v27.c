1)

static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int result = 0;
   
    while(n-- > 0) {
        result = result << 1;
        if (s->bit_index == 0) {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFFu);
        }
        s->bit_index--;
        result |= (bytestream2_peek_byte(&s->g) >> s->bit_index) & 1;
    }
    return result;
}


2)

static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    int index;
    int boundaryValue = 0xFFu;
    for (index = n; index > 0; index--) {
        res <<= 1;
        if (s->bit_index == 0) {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != boundaryValue);
        }
        s->bit_index--;
        res |= (bytestream2_peek_byte(&s->g) >> s->bit_index) & 1;
    }
    return res;
}

static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;

    for(;n > 0; n--) {
        res <<=1;
        if(!s->bit_index) {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFFu);
        }
        s->bit_index--;
        res |= ((bytestream2_peek_byte(&s->g) >> s->bit_index) & 1);
    }
    return res;
}`
