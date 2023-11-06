Variant 1:


static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int i;
    int res = 0;
    for (i=n; i!=0; i--) {
        s->bit_index--;
        if (s->bit_index < 0) {
            s->bit_index = bytestream2_get_byte(&s->g) != 0xFFu ? 7 : 8;
        }
        res = (res << 1) | ((bytestream2_peek_byte(&s->g) >> s->bit_index) & 1);
    }
    return res;
}


Variant 2:


static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    s->bit_index += n;
    while (n--) {
        s->bit_index--;
        if (s->bit_index == 0) {
            s->bit_index = 8 - ((bytestream2_get_byte(&s->g) == 0xFFu)? 0 : 1);
        }
        res = res << 1;
        res = res | ((bytestream2_peek_byte(&s->g) >> s->bit_index) & 1);
    }
    return res;
}


Variant 3:


static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    do {
        if(s->bit_index == 0) {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFFu);
        }
        res = (res << 1) | (bytestream2_peek_byte(&s->g) >> --s->bit_index & 1);
    } while(--n > 0);
    return res;
}

  
Variant 4:


static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if(s->bit_index == 0)
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFF);
        s->bit_index--;
        res = res << 1 | (bytestream2_peek_byte(&s->g) >> s->bit_index & 1);
    }
    return res;
}
