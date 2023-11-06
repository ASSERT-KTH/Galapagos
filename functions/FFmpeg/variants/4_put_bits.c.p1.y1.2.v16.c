// Option 1: Recursive implementation
static void put_bits(Jpeg2000EncoderContext *s, int val, int n) 
{
    if (n-- > 0)
    {
        if (s->bit_index == 8)
        {
            s->bit_index = *s->buf == 0xff;
            *(++s->buf) = 0;
        }
        *s->buf |= val << (7 - s->bit_index++);
        put_bits(s, val, n);
    }
}

// Option 2: Switching while loop to for loop
static void put_bits(Jpeg2000EncoderContext *s, int val, int n) 
{
    int i;
    for(i=0; i<n; i++)
    {
        if (s->bit_index == 8)
        {
            s->bit_index = *s->buf == 0xff;
            *(++s->buf) = 0;
        }
        *s->buf |= val << (7 - s->bit_index++);
    }
}

// Option 3: Using do-while loop
static void put_bits(Jpeg2000EncoderContext *s, int val, int n)
{
    if (n <= 0)
        return; 

    do {
        if (s->bit_index == 8)
        {
            s->bit_index = *s->buf == 0xff;
            *(++s->buf) = 0;
        }
        *s->buf |= val << (7 - s->bit_index++);;
    }while (--n > 0);
}