static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int count = n;  
    int accum = 0;  

    while (count-- > 0) {
        accum *= 2;
        if (0 == s->bit_index) {
            s->bit_index = 7 + (!((bytestream2_get_byte(&s->g)) ^ 0xFFu));
        }
        --s->bit_index;
        accum |= ((bytestream2_peek_byte(&s->g) >> s->bit_index) % 2);
    }
    return accum;
}
