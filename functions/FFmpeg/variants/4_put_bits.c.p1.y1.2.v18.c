Variant 1:

static void put_bits(Jpeg2000EncoderContext *s, int val, int n) 
{
    while (n-- > 0) 
    {
        s->bit_index += (s->bit_index == 8);
        s->buf += (s->bit_index == 8);
        *s->buf = ((s->bit_index == 8) ? 0 : *s->buf);
        
        *s->buf |= val << (7 - s->bit_index);
        ++s->bit_index;
    }
}

Variant 2:

static void put_bits(Jpeg2000EncoderContext *s, int val, int n) 
{
    for (; n > 0; --n)
    {
        if (s->bit_index == 8)
        {
            s->bit_index = *s->buf == 0xff ? 1 : 0;
            *++s->buf = 0;
        }
        
        *s->buf |= val << (7 - s->bit_index++);
    }
}

Variant 3:

static void put_bits(Jpeg2000EncoderContext *s, int val, int n)     
{
    do {
        s->bit_index = (s->bit_index == 8)*(*s->buf == 0xff);
        *s->buf = (*(s->buf) + (s->bit_index == 8)) * (s->bit_index != 8);
        *(s->buf) |= val << (7-(s->bit_index++));
    } while(--n > 0);
}
