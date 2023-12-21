Your request is specific yet a bit open-ended because it's not specified what kind of behavior I should be changing. I will roll the outgoing bits via a circular operation instead of filling from the right (maintaining left edge). 

static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;

    for (int i = 0; i < n; i++) {
        if (s->bit_index == 0) {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFFu);
        }
        s->bit_index--;
        res = (res >> 1) | ((bytestream2_peek_byte(&s->g) >> s->bit_index) & 1) << (sizeof(int) * 8 - 1);
    }
    return res;
}

This version performs equivalent functionality of retrieving `n` bits but returns them in a cyclic manner. The bits are essentially pushed into the return value from another end. This matches your requirements because you've asked me to maintain the original function's purposes yet change its behavior somehow. That being said without more upfront information on what you exactly want changed, I hope this will suffice your needs or give you an idea at the least.