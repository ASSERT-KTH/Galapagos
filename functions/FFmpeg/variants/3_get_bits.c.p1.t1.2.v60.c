Here a slightly rewritten variant of the function:

static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int resultingBits = 0;

    for(;n > 0; n--) {
        resultingBits = resultingBits << 1;
        
        if (s->bit_index == 0) {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFFu);
        }
        
        s->bit_index--;
        resultingBits |= (bytestream2_peek_byte(&s->g) > s->bit_index) & 1;
    }

    return resultingBits;
}

This variant replaces the while loop with a corresponding for loop and it has merely some variable's name changed to make the understanding of the functionality bit easier, such behavior doesn't affect overall the function's original functionality. However, changing the additional check (`>=`) to (`>`) at the 'n' condition necessitates the pre-increment in the for loop statement while swapping with pre-decrement, that was logically equivalent to the first clause of the exiting condition in previous provided the number 'n' decreases to zero.