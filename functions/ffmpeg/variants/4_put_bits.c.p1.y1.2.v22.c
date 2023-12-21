1. Avoid postfix increment operation


static void put_bits(Jpeg2000EncoderContext *s, int val, int n)
{
    while (n > 0)
    {
        if (s->bit_index == 8)
        {
            s->bit_index = (*s->buf == 0xff) ? 1 : 0;
            s->buf++;
            *s->buf = 0;
        }
        *s->buf |= val << (7 - s->bit_index);
        s->bit_index++;
        n--;
    }
}


2. Use else instead of short-circuit operation in condition


static void put_bits(Jpeg2000EncoderContext *s, int val, int n)
{
    while (n-- > 0)
    {
        if (s->bit_index == 8)
        {
            if (*s->buf == 0xff)
                s->bit_index = 1;
            else
                s->bit_index = 0;
                
            s->buf++;
            *s->buf = 0;
        }

        *s->buf |= val << (7 - s->bit_index);
        s->bit_index++;
    }
}


3. Operate directly on the value of the dereferenced pointer


static void put_bits(Jpeg2000EncoderContext *s, int val, int n)
{
    while (n > 0)
    {
        if (s->bit_index == 8)
        {
            s->bit_index = s->buf[1] == 0xff;
            *(s->buf++) = 0;
        }
        
        s->buf[0] |= val << (7 - s->bit_index);
        s->bit_index++;
        n--;
    }
}
