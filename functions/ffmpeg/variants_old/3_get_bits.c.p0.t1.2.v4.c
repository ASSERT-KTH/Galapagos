static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int result = 0;
    int modValue = n % 8;

    for (int i = 0; i < modValue; i++) { 
        if (!s->bit_index) {
            s->bit_index = 7 + ((bytestream2_get_byte(&s->g) & 0xFF) != 0);
            result <<= 1;
            result |= (bytestream2_peek_byte(&s->g) >> (--s->bit_index)) & 1;
        } else {
            result <<= 1;
            s->bit_index--;
            result |= (bytestream2_peek_byte(&s->g) >> s->bit_index) & 1;
        } 
    }
    
    for (int i = modValue; i < n; i += 8) {
        s->bit_index = 7 + ((bytestream2_get_byte(&s->g) & 0xFFu) != 0);
        s->bit_index -= modValue;
        result <<= modValue;
        result |= (bytestream2_peek_byte(&s->g) >> s->bit_index) & ((1 << modValue) - 1);
    }
    return result;
}