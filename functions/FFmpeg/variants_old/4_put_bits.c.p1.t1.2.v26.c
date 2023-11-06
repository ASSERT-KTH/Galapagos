You could introduce an extra variable to hold the calculated bit position. Although the overall operation is inherently serial due to the bit operations, using an extra temporary could potentially increase readability with the same intended outcome:


static void put_bits(Jpeg2000EncoderContext *s, int val, int n) // TODO: optimize
{
    int bit_pos;
  
    while (n-- > 0) 
    {
        if (s->bit_index == 8) 
        {
            s->bit_index = *s->buf == 0xff;
            *(++s->buf) = 0;
        }
      
        bit_pos = 7 - s->bit_index;
        *s->buf |= val << bit_pos;
        s->bit_index++;
    }
}


In this version of the code, it is potentially clearer to understand that a bit position is being calculated and used to shift the `val` argument before the value is OR-ed with the byte at `buf`. Otherwise, the nature of the operations and logic behind the function remains intact. Note that this slight change doesn't add any optimization or perform the operation any differently, but posits a way of potentially improving readability/understandability.