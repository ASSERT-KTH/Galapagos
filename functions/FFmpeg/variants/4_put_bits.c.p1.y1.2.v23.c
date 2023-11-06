Variant 1:


static void put_bits(Jpeg2000EncoderContext *s, int val, int n)
{
    for (int i = 0; i < n; i++){
        if(s->bit_index == 8){
            s->bit_index = (*s->buf) ? 1 : 0;
            *(++s->buf) = 0;
        }
        *s->buf |= val << (7 - (s->bit_index++));
    }
}


Variant 2:


static void put_bits(Jpeg2000EncoderContext *s, int val, int n)
{
    int counter = n;
    while(counter--){
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
    do{
        if (s->bit_index == 8)
        {
            s->bit_index = *s->buf == 0xff ? 1: 0;
            *++s->buf = 0;
        }
        *s->buf |= val << (7 - (s->bit_index++));
    } while(--n);
}


Variant 4:


static void put_bits(Jpeg2000EncoderContext *s, int val, int n)
{
    while (n > 0)
    {
        if (s->bit_index == 8)
        {
            s->bit_index = (s->buf[0] == 0xff) ? 1 : 0;
            s->buf[1] = 0;
            s->buf++;
        }
        s->buf[0] |= val << (7 - s->bit_index++);
        n--;
    }
}
