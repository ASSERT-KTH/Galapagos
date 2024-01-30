1)
static int get_bits(Jpeg2000DecoderContext *s, int n){
    int res = 0;
    while (n-- > 0) {
        res = res << 1;
        if (s->bit_index == 0){
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 255);
        }
        s->bit_index = s->bit_index - 1;
        res = res | ((bytestream2_peek_byte(&s->g) >> s->bit_index) & 1);
    }
    return res;
}

2)
static int get_bits(Jpeg2000DecoderContext *s, int n){
    n = n - 1;
    int res = 0;
    while (n >= 0){
        res <<= 1;
        if (0 == s->bit_index){
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFFu);    
        }
        --s->bit_index;
        res |= (bytestream2_peek_byte(&s->g) >> s->bit_index) & 1;
        n--;
    }
    return res;
}

3)
static int get_bits(Jpeg2000DecoderContext *s, int n){
    int res = 0;
    for (;n > 0; n--){
        res = res << 1;
        if (s->bit_index == 0){
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFFu);    
        }
        s->bit_index--;
        res = res | ((bytestream2_peek_byte(&s->g) >> s->bit_index) & 1);
    }
    return res;
}
