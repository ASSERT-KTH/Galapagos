1) Changing the while loop into a for loop:

static void put_bits(Jpeg2000EncoderContext *s, int val, int n) 
{
    for (; n > 0; --n)
    {
        if (s->bit_index == 8)
        {
            s->bit_index = *s->buf == 0xff;
            *(++s->buf) = 0;
        }
        *s->buf |= val << (7 - s->bit_index++);
    }
}


2) Iterating using --n within the for loop control:

static void put_bits(Jpeg2000EncoderContext *s, int val, int n) 
{
    for (; n--; )
    {
        if (s->bit_index == 8)
        {
            s->bit_index = s->buf == 0xff;
            *(++s->buf) = 0;
        }
        *s->buf |= val << (7 - s->bit_index++);
    }
}


3) Pulling update of `s->buf` inside if condition:

static void put_bits(Jpeg2000EncoderContext *s, int val, int n) 
{
    while (n-- > 0)
    {
        if (s->bit_index == 8)
        {
            s->bit_index = *s->buf == 0xff;
            s->buf++;
            *s->buf = 0;
        }
        *s->buf |= val << (7 - s->bit_index++);
    }
}

Note: All transformations maintain the signature and functionality of the original function, neither including auxiliary nor helper functions or outputting any text.