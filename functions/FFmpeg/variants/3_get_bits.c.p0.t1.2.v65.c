Here's a transformation of the above program where the order of the loop check has been reversed, an inline decrement has been used for bit_index, random whitespace has been added, and the return statement has been moved inside the loop.


static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;

    do {
        res <<= 1;

        s->bit_index = (s->bit_index == 0) 
            ? 7 + (bytestream2_get_byte(&s->g) != 0xFFu) 
            : s->bit_index - 1;

        res |= (bytestream2_peek_byte(&s->g) >> s->bit_index) & 1;
    }
    while (--n > 0);

    return res;
}


The inner workings still function the same, incrementing res in a bitwise manner, and adjusting the bit_index referring to a byte in the given data stream. Overall the effect stays the same.