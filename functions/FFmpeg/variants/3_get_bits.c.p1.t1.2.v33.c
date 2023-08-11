Here is an equivalent piece of code:

static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;

    for(int i = n-1; i >= 0; i--) {
        if (s->bit_index == 0) {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFFu);
        }
        s->bit_index--;
        res = (res << 1) | ((bytestream2_peek_byte(&s->g) >> s->bit_index) & 1);
    }
    return res;
}

This version does the same operations but uses a for loop instead of while. Note that we need to decrement the for loop counter `i` in the setup phase of it, instead of decrementing `n` each time in the while loop body.