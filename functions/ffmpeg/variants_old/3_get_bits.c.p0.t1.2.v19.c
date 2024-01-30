static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    int tmp;

    --n; 
    while (n >= 0) {
        res <<= 1;
        if (s->bit_index == 0) {
            tmp = bytestream2_get_byte(&s->g);
            s->bit_index = tmp != 0xFFu ? 8 : 7;
        }
       
        --(s->bit_index);
        
        res |= ((bytestream2_peek_byte(&s->g) & (1 << s->bit_index)) != 0);
        --n;
    }
    return res;
}