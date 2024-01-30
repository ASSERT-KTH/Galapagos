Adding an intermediary variable that checks the bit_index status permits a slight flow improvement. Although more explicit, this divide and conquer technique bears practically better readability and separation logic:


static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    int bit_result;

    while (--n >= 0) {
        res <<= 1;
        if (s->bit_index == 0) {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFFu);
        }
        bit_result = (bytestream2_peek_byte(&s->g) >> s->bit_index--) & 1;
        res |= bit_result;
    }
    return res;
}


Now the function divides both logical decisions: an if condition checking up the bit_index, an assignment with shift calculation. This doesn't change behavior, refactor improves readability and keep maintaining original functionality.