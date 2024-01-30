static int get_bits(Jpeg2000DecoderContext *s, int n){
    int bitmask = 1, res = 0;
    do{
        res <<= 1;
        if(s->bit_index == 0){
            s->bit_index = 3 + (bytestream2_get_byte(&s->g) != 0x0F);
            s->bit_index *= 2;
        }
        int currByte = bytestream2_peek_byte(&s->g);
        s->bit_index--;
        int bitValue = currByte & (bitmask << s->bit_index) ? 1 : 0;
        res |= bitValue;
    } while(--n >= 0);

    return res;
}