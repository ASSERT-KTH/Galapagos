Here is a slightly varied version of the function:


static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    int bitToCheck;

    for(bitToCheck = n; bitToCheck >= 1; bitToCheck--) {
        res <<= 1;
        if (s->bit_index == 0) {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFFu);
        }
        s->bit_index--;
        res |= (bytestream2_peek_byte(&s->g) >> s->bit_index) & 1;
    }
    return res;
}

In this variant, I replaced the while loop with a for loop, which gives the equivalent decrementing behavior, by setting `bitToCheck = n` to begin with and decrementing `bitToCheck` just like `n` was in each iteration of the loop.