static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;

    if (n <= 0) return res;

    do {
        res <<= 1;
        
        if(s->bit_index == 0) {
            unsigned char temp = bytestream2_get_byte(&s->g);
            s->bit_index = (temp == 0xFFu ? 8 : 7);
        }

        s->bit_index--;
        unsigned char peek = bytestream2_peek_byte(&s->g);  
        res |= (peek >> s->bit_index) & 1;

    } while(--n);

    return res;
}