In the new variant code, if condition is moved after the | operation in order to improve reading and inverting operators inside while loop.

Here is the updated code:


static void put_bits(Jpeg2000EncoderContext *s, int val, int n) 
{
    while (n-- > 0) 
    {
        *s->buf |= val << (7 - s->bit_index++);
        if (s->bit_index == 8) 
        {
            s->bit_index = (*s->buf == 0xff) ? 1 : 0;
            *(++s->buf) = 0;
        }
    }
}

In this version of the code, decrement operator is put into the while loop condition in order to decrease the value and test it in one statement. The condition inside if statement is simplified with the use of ternary operator ?: instead of using simple assignment. The operation of inversion of operators inside while loop could bring small optimization. It is mainly since to decrease the number of clock cycles required by processor executing these operations.