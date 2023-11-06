Here are a few code transformations which shall maintain the major parts of the original code and it's functionalities while modifying certain aspects. The changes primarily involve loop structuring and a slight reordering of operations to preserve encapsulated logic.

Transformation 1:


static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    n--;

    while (true) {
        res = (res << 1 | ((bytestream2_peek_byte(&s->g) >> s->bit_index--) & 1));
        if (s->bit_index < 0) {
            s->bit_index = 7 + bytestream2_get_byte(&s->g);
        }

        if (n < 0) {
            break;
        }

        n--; 
    }

    return res;
}


Transformation 2:


static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
 
    do
    {
	if (s->bit_index == 0) {
            s->bit_index = 7 + bytestream2_get_byte(&s->g);
        }
        res = (res << 1) | (bytestream2_peek_byte(&s->g) >> s->bit_index) & 1;
        s->bit_index--;

    } while (--n >= 0);
   
    return res;
}


Transformation 3:


static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    for(; n>0; n--){
        res = (res << 1);
        if (s->bit_index == 0){
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFFu);
        }
        s->bit_index--;
        res = (res | ((bytestream2_peek_byte(&s->g) >> s->bit_index) & 1));
    }
    return res;
}
