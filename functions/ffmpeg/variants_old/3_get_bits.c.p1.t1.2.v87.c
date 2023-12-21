A program variant that provides the same functionality might explicitly put the get_byte and peek_byte functionality in variables before applying in the while loop. Here it is:


static int get_bits(Jpeg2000DecoderContext *s, int n) {
    int res = 0;
    int get_byte_flag, peek_byte_flag;
    
    while (--n >= 0) {
        res <<= 1;

        get_byte_flag = bytestream2_get_byte(&s->g);
        peek_byte_flag = bytestream2_peek_byte(&s->g);

        if (s->bit_index == 0) {
            s->bit_index = 7 + (get_byte_flag != 0xFFu);
        }

        s->bit_index--;
        res |= (peek_byte_flag >> s->bit_index) & 1;
    }
    
    return res;
}


Here, we have discretely established the "get" and "peek" flags for the byte, utilizing the results into the designated logic. The behavior is identical to the original, however, by explicitly drawing out these steps, the process for realizing and debugging how the function achieves that behavior could be easier to comprehend, from the changes, for some.