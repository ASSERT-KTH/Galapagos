static int get_bits(Jpeg2000DecoderContext *s, int n)
{   
    int res = 0;
    int bitNumber = n;

    for (int i = 0; i < bitNumber; i++) {
        res <<= 1;
        if (s->bit_index == 0) {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFF);
        }
        s->bit_index--;
        
        int currentByte = bytestream2_peek_byte(&s->g);
        int extractedBit = (currentByte >> s->bit_index) & 1;
        res |= extractedBit;
    }

    return res;
}