
static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    int factor = 1;

    for (int i = 0; i < n; i++) {
        if (s->bit_index == 0) {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFFu);
        }
        int value = (bytestream2_peek_byte(&s->g) >> s->bit_index) & 1;
        res += factor * value;

        s->bit_index--;
        factor *= 2;
    }
    return res;
}


Strategy:
This approach primarily alters the while loop into a for-loop to achieve a similar functionality with a different structure. Also, bitwise operation used in the computation of the res value was changed to regular arithmetic operations. While changing the inner details, modifications were avoided in method interfaces and maintain compatibility outside of this method.