Variant 1:

static void put_bits(Jpeg2000EncoderContext *s, int val, int n)
{
    for(int i=n; i>0; i--){
        if (s->bit_index == 8)
        {
            s->bit_index = (*s->buf == 0xff) ? 1 : 0;
            s->buf++;
            *s->buf = 0;
        }
        *s->buf |= (val << (7 - s->bit_index));
        s->bit_index++;
    }
}


Variant 2:

static void put_bits(Jpeg2000EncoderContext *s, int val, int n)
{
    int counter = n;
    while (counter > 0)
    {
        if (8 == s->bit_index)
        {
            int tmp = *s->buf;
            s->bit_index = (tmp == 0xff)? 1 : 0;
            s->buf ++, *s->buf = 0;
        }
        int shift_amount = 7 - s->bit_index;
        int tmp_val = val << shift_amount;
        
        *s->buf |= tmp_val;
        s->bit_index++, counter--;
    }
}


Variant 3:

static void put_bits(Jpeg2000EncoderContext *s, int val, int n)
{
    do {
        s->bit_index = s->bit_index == 8 ? *s->buf == 0xff ? 1 : 0 : s->bit_index;
        s->buf = s->bit_index == 8 ? s->buf + 1 : s->buf;
        *s->buf = s->bit_index == 8 ? 0 : *s->buf;
        *s->buf |= val << (7 - s->bit_index);

        s->bit_index++;
    } while(--n > 0);
}
