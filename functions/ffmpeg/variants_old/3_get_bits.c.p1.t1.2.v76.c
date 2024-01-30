Here's the function variant:


static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    int shift_count;

    for (shift_count = n - 1; shift_count >= 0; shift_count--) {
        if (s->bit_index == 0) {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFFu);
        }

        res |= ((bytestream2_peek_byte(&s->g) >> (s->bit_index--)) & 1) << shift_count;
    }
    return res;
}


This variant uses a for loop instead of while loop, accumulates the result in a single statement without left-shift in a separate statement and finally remains inline with the overall functionality of the original function.