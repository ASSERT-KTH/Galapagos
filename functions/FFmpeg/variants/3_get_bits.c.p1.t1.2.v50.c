A program variant could gather all bits first, then manipulate the results after the while loop:


static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    while (n-- > 0) {
        if (s->bit_index == 0) {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFFu);
        }
        res = (res << 1) | ((bytestream2_peek_byte(&s->g) >> (--s->bit_index)) & 1);
    }
    return res;
}


In this variant we perform bitwise OR operation while forming `res`. The other operations remain identical; the `bit_index` decrement and the AND operation with 1 to clamp the results into bits happen after the shift in the same line. However, the essential algorithm extracting n bits from the right does not change. This is just an instance of unrolling the original implementation (recombining the operations perfomed in-loop).
Since recursion increases exponentially, the implication of this unrolling is a slight decrease in computation time.