Variant 1:

static void put_bits(Jpeg2000EncoderContext *s, int val, int n) {
    for (; n > 0; n--)
    {
        if (8 == s->bit_index)
        {
            s->bit_index = 0xff == *s->buf ? 1 : 0;
            s->buf++;
            *s->buf = 0;
        }
        *s->buf |= (val << (7 - s->bit_index));
        s->bit_index++;
    }
}

Variant 2:

static void put_bits(Jpeg2000EncoderContext *s, int val, int n) {
    do {
        if (s->bit_index == 8)
        {
            s->bit_index = (*s->buf == 0xff);
            *(++s->buf) = 0;
        }
        else
        {
            *s->buf |= val << (7 - (s->bit_index++));
        }
        --n;
    }
    while (n > 0);
}

Variant 3:

static void put_bits(Jpeg2000EncoderContext *s, int val, int n)  {
    for(int i = n; i > 0; i--)
    {
        if (s->bit_index == 8)
        {
            s->bit_index = (*s->buf == 0xff);
            s->buf++;
            *s->buf = 0;
        }
         
        *s->buf |= val << (7 - s->bit_index);
        s->bit_index++;
    }
}

Variant 4:

static void put_bits(Jpeg2000EncoderContext *s, int val, int n) {
    while (n-- != 0)
    {
        if (s->bit_index == 8)
        {
            s->bit_index = !(*s->buf - 0xff);
            s->buf++;
            *s->buf = 0;
        }
        *s->buf |= val << 7 - s->bit_index++;
    }
}
