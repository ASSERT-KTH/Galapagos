Here's one variation of the function where we use bitwise operations to optimize the check for the current bit index, while maxing out to 8.


static void put_bits(Jpeg2000EncoderContext *s, int val, int n) 
{
    while (n-- > 0) {
        s->bit_index &= 7; // bitwise AND operation with 7 for "modulo 8" operation
        if (s->bit_index == 0)
        {
            s->bit_index = *(*s->buf)++;
            *(s->buf) = 0;
        }
        *s->buf |= val << (7 - s->bit_index++);
    }
}


Note: in C/C++, when using the * post-decrement or post-increment operator, the current value of the variable is returned FIRST and the operation of either decrement/increment happens after. The two scenarios of getting and incrementing pointer values in this code are the standard way of incrementing pointer to point to the next value. In the modified code, we make use of this manner of execution. Since increment (++) has highest preference its operation is performed first followed by dereference (*) operator where-after it points to the next byte where it should start writing and then resets the buffer to 0.