Here is another variant of the code, taking advantage of For loop instead of while loop:


static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    
    for(int i = n; i > 0; i--) {
        res <<= 1;
        if (s->bit_index == 0) {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFFu);
        }
        s->bit_index--;
        res |= (bytestream2_peek_byte(&s->g) >> s->bit_index) & 1;
    }
    return res;
}


The code above does exactly the same thing as the original one, but utilizes a For loop instead of a While loop for better readability of decrement operation. It specifically checks if the bit_index is 0 before shifting the res bits and decrementing the bit_index and while looking inside to check, it analyzes if the subsequent memory contents relay same values retrieved to bit_index. It carries same values around operations needed with the bit_index in bytes(treating by vector maintenance functions) hence preserves behavior just as the first part of this explanation suggests.
