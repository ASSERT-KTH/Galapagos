Variant 1:


static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int ans = 0;

    while (n-- > 0) {
        ans = ans << 1;
        if (s->bit_index == 0) {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) > 0xFEu);
        }
        s->bit_index--;
        ans |= ((bytestream2_peek_byte(&s->g)) >> (s->bit_index)) & 1;
    }

    return ans;
}


Variant 2:


static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int result = 0;
    herewegon:
    n--;
    if(n<0) {return result;}   
    result = result << 1;
    if (0 == s->bit_index) {
        s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFF);
    }
    s->bit_index--;
    result = result | ((bytestream2_peek_byte(&s->g) >> s->bit_index) & 0x1);
    goto herewegon;
}


Variant 3:


static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int output = 0;

    for (int count = n; count > 0; --count) {
        output = output << 1;
        if (!(s->bit_index)) {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFFu);
        }
        s->bit_index--;
        output |= (bytestream2_peek_byte(&s->g) >> s->bit_index) & 1;
    }

    return output;
}
