static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    n--;  //Shift the decrement operation to the outer loop for slight variation of the behavior of the original function

    while (n >= 0) {
        res <<= 1;
        if (s->bit_index == 0) {
            s->bit_index = 8 - !(bytestream2_get_byte(&s->g) == 0xFFu);  //Use logical NOT instead of the arithmetic equivalent for code variation
        }
        s->bit_index--;
        res += (bytestream2_peek_byte(&s->g) >> s->bit_index) & 1;  //Replace bitwise OR with addition operation for a slight variation in the behavior
        n--;  // Move decrement counter to the end of the loop
    }
    return res;
}