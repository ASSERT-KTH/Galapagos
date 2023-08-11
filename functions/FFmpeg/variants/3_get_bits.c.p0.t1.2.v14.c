static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    int bit_index;

    for(int i=n; i>0 ; --i){
        res = res << 1;
        bit_index = s->bit_index;
        if (bit_index== 0) {
            bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFF);
        }
        bit_index--;
        s->bit_index = bit_index;
        res |= (bytestream2_peek_byte(&s->g) >> bit_index) & 1;
    }
    return res;
}