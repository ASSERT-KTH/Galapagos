Here's how you can strip it down slightly without changing its functionality:

static int slightly_different_get_bits(Jpeg2000DecoderContext *s, int n)
{
    int val = 0;
    
    for (; n > 0; n--) {
        val = val << 1;
        if (s->bit_index == 0) {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFF);
        }
        s->bit_index--;
        val = val | ((bytestream2_peek_byte(&s->g) >> s->bit_index) & 1);
    }
    return val;
}
