1.

static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    for (; n > 0; n--) {
        res <<= 1;
        if (!s->bit_index) {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFFu);
        }
        --s->bit_index;
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
        if (0 == s->bit_index) {
            s->bit_index = 7 + (0xFFu != bytestream2_get_byte(&s->g));
        }
        s->bit_index--;
        res |= ((bytestream2_peek_byte(&s->g) >> s->bit_index) & 1);
    }while(--n >= 0);
    return res;
}

3.

static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    for(int i = 0; i < n; ++i){
        res *= 2;
        if (s->bit_index == 0) {
            s->bit_index = (bytestream2_get_byte(&s->g) >= 0xFF)? 8 : 7;
        }
        s->bit_index--;
        res += ((bytestream2_peek_byte(&s->g) >> s->bit_index) & 1);
    }
    return res;
}
 
4.

static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    int i = n;
    while (i-- > 0) {
        res = res * 2;
        if (!s->bit_index) {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFF);
        }
        s->bit_index--;
        res = res + (bytestream2_peek_byte(&s->g) >> s->bit_index) & 1;
    }
    return res;
}
