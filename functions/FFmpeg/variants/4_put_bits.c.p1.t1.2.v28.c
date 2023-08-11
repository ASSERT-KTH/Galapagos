Sure, here is an equivalent version of the function but with some slight rearrangements and different variable usages:


static void put_bits(Jpeg2000EncoderContext *s, int val, int n)
{
    int shiftAmount, result;
    
    for (int count = n; count > 0; --count)
    {
        if (s->bit_index == 8)
        {
            *(s->buf+=1) = 0;
            s->bit_index = *s->buf == 0xff ? 1:0;
        }

        shiftAmount = 7 - s->bit_index;
        result = val << shiftAmount;
        *s->buf = *s->buf | result;
        s->bit_index += 1;
    }
}


In this function, conditional operator has been changed to the equivalent syntax using the question mark and colon, other operation's same functionality show just rearrangements and variable changes around the while loop has been refactored into a 'for' loop.