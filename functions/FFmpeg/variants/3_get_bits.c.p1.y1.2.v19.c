Variant 1:

static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int val;
    for ( val = 0; n--; ) {
        val <<= 1;
        if ( !(s->bit_index) ) {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFFu);
        }
        s->bit_index--;
        val |= (bytestream2_peek_byte(&s->g) >> s->bit_index) & 1;
    }
    return val;
}


Variant 2:

static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int bits=0;
    for( ;n;--n) {
        bits = (bits << 1) ; 
            
        if (!s->bit_index) {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g)-0xFFu);
        }
        --s->bit_index;
        
        bits |= (bytestream2_peek_byte(&s->g) >> s->bit_index) & 1;
    }
    return bits;
}

Variant 3:

static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int result = 0;
    
    do {
        result = result *2;
        
        if(s->bit_index == 0) {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFF);
        }
        s->bit_index--;

        result |= (bytestream2_peek_byte(&s->g) >> s->bit_index) & 1;
        
    } while(--n+1);
    
    return result;
}
