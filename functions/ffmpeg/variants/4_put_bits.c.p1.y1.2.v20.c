Variant 1:

static void put_bits(Jpeg2000EncoderContext *s, int val, int n) 
{
    for (int bits_left=n; bits_left>0; bits_left--)
    {
        if (s->bit_index == 8)
        {
            s->bit_index = *s->buf == 0xff;
            *(++s->buf) = 0;
        }
        *s->buf |= val << (7 - s->bit_index++);
    }
}

Variant 2:

static void put_bits(Jpeg2000EncoderContext *s, int val, int n) 
{
    do
    {
        if (s->bit_index == 8)
        {
            s->bit_index = *s->buf == 0xff;
            *(++s->buf) = 0;
        }
        *s->buf |= val << (7 - s->bit_index++);
        n--;
    } 
    while (n > 0);
}


Variant 3:

static void put_bits(Jpeg2000EncoderContext *s, int val, int n) 
{
    for (; n; --n)
    {
        if (s->bit_index == 8)
        {
            s->bit_index = (*s->buf == 0xff) ? 1 : 0;
            *++s->buf = 0;
        }
        *s->buf |= (val << (7 - s->bit_index++));
    }
}

Variant 4:

static void put_bits(Jpeg2000EncoderContext *s, int val, int n) 
{
    while (1)
    {
        if (s->bit_index == 8)
        {
            s->bit_index = *s->buf == 0xff;
            *(++s->buf) = 0;
        }
        *s->buf |= val << (7 - s->bit_index++);
        if (--n <= 0)
            break;
    }
}
