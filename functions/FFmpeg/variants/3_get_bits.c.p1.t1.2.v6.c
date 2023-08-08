static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    int temp = 0;

    for(int i=n-1; i>=0; --i){
        temp = (bytestream2_peek_byte(&s->g) >> s->bit_index) & 1;
        res |= temp << i;

        if (s->bit_index == 0){
            s->bit_index = 8 - (bytestream2_get_byte(&s->g) == 0xFFu ? 0 : 1);
        } else {
            s->bit_index--;
        }
    }
    
    return res;
}