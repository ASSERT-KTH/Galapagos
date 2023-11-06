static void put_bits(Jpeg2000EncoderContext *s, int val, int n)
{
    int i = 0;
    for (i; i < n; i++)
    {
        if (s->bit_index == 8)
        {
            s->bit_index = *s->buf == 0xff;
            *(s->buf + 1) = 0;
            s->buf++;
        }
        *s->buf |= val << (7 - s->bit_index);
        s->bit_index++;
    }
}

static void put_bits(Jpeg2000EncoderContext *s, int val, int n)
{
    while (n-- != 0)
    {
        int is_buf_full = (s->bit_index == 8) ;
        if (is_buf_full){
            s->bit_index = (*s->buf == 0xff) ? 1 : 0;
            s->buf++;
            *s->buf = 0;
        }
        *s->buf |= (val << (7 - s->bit_index));
        s->bit_index++;
    }
}

static void put_bits(Jpeg2000EncoderContext *s, int val, int n)
{
    do 
    {
        if (s->bit_index == 8){
            s->bit_index = (*s->buf == 0xff) ? 1 : 0;
            *++s->buf = 0;
        }

        *s->buf |= val << (7 - s->bit_index);
        s->bit_index++;

    } while (--n != 0);
}