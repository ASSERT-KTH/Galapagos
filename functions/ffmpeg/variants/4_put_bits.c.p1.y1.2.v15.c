Below, is the optimized version of the code mentioned above.
The improved version switches from a while-loop to a for-loop, and it also optimizes bit manipulations that were occurring halfway in the loop.

static void put_bits(Jpeg2000EncoderContext *s, int val, int n)
{   
    int currentShift = 0;

    for (int i = n-1; i >= 0; --i) 
    {
        if (s->bit_index == 8)
        {
            s->bit_index = *s->buf == 0xff;
            *(++(s->buf)) = 0;
        }
        currentShift = 7 - s->bit_index;
        *(s->buf) |= (val << currentShift) & (1 << currentShift);
        ++(s->bit_index);
    }
}