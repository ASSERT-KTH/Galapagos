// Variant 1: refactor with for loop
static void put_bits(Jpeg2000EncoderContext *s, int val, int n) 
{
    for(; n > 0; --n)
    {
        if (s->bit_index == 8)
        {
            s->bit_index = *s->buf == 0xff;
            *(++s->buf) = 0;
        }
        *s->buf |= val << (7 - s->bit_index++);
    }
}

// Variant 2: merge increment/decrement operations to one line
static void put_bits(Jpeg2000EncoderContext *s, int val, int n) 
{
    while (--n >= 0)
    {
        if ((s->bit_index = *s->buf == 0xff? 0 : s->bit_index + 1) == 8)
        {
            *(++s->buf) = 0;
        }
        *s->buf |= val << (7 - s->bit_index);
    }
}

// Variant 3: tidy up parentheses to clarify intention of the mask shift
static void put_bits(Jpeg2000EncoderContext *s, int val, int n) 
{
    while (n-- > 0) 
    {
        if (s->bit_index == 8) 
        {
            s->bit_index = (*s->buf == 0xff);
            *(++s->buf) = 0;
        }
        *s->buf |= (val << (7 - s->bit_index++));
    }
}

// Variant 4: combine != comparison for bit_index
static void put_bits(Jpeg2000EncoderContext *s, int val, int n) 
{
    while (n-- > 0) 
    {
        s->bit_index = (s->bit_index != 8)? s->bit_index : (*s->buf == 0xff? 1 : 0);
        *(++s->buf) = 0;
        *s->buf |= val << (7 - (s->bit_index++));
    }
}

// Variant 5: make the bit shift operation first
static void put_bits(Jpeg2000EncoderContext *s, int val, int n) 
{
    while (n-- > 0) 
    {
        *s->buf |= val << (7 - s->bit_index);
        if (s->bit_index++ == 8) 
        {
            s->bit_index = (*s->buf == 0xff? 1 : 0);
            *(++s->buf) = 0;
        }
    }
}