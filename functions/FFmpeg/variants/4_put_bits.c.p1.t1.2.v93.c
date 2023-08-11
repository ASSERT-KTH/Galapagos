Sure, here's an alternate implementation of the function:


static void put_bits(Jpeg2000EncoderContext *s, int val, int n) 
{
    for (int i = n-1; i >= 0; i--){
        if (s->bit_index == 8)
        {
            s->bit_index = *s->buf == 0xff;
            *(++s->buf) = 0;
        }
        *s->buf |= ((val >> i) & 1) << (7 - s->bit_index++);
    }
}


This provides the same functionality, but flips the order in which bits from the input `val` are added to the context buffer--now iterates from left to right (most significant bit to least significant bit), instead of right to left as the original version does.