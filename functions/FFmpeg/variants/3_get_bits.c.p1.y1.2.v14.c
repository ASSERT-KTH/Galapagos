Variant 1:

static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    int indexDecrementAboveZero, indexEqualZeroCheck, bitAndOperationRes;
    
    n--;
    do {
        res *= 2;

        indexEqualZeroCheck = (s->bit_index == 0);
        indexDecrementAboveZero = s->bit_index--;
        
        if (indexEqualZeroCheck) {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFFu);
        }
        
        bitAndOperationRes = (bytestream2_peek_byte(&s->g) >> indexDecrementAboveZero) & 1;
        res |= bitAndOperationRes;
    } while (n-- > 0);
    
    return res;
}

Variant 2:

static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    
    for(;n>0;n--) {
        res <<= 1;

        if (s->bit_index == 0) {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFFu);
        }

        s->bit_index--;
        
        res |= (bytestream2_peek_byte(&s->g) >> s->bit_index) & 1; 
    }
    
    return res;
}

Variant 3:

static int get_bits(Jpeg2000DecoderContext *s, int n)
{        
    int res = 0;

    if(n<=0)
        return res;
    
    do {
        res = res << 1;

        if (s->bit_index == 0)
            s->bit_index =7 + (bytestream2_get_byte(&s->g) != 0xFFu);
        
        s->bit_index--;
        
        res |= (bytestream2_peek_byte(&s->g) >> s->bit_index) & 1;
    } while(--n > 0);
    
    return res;
}
