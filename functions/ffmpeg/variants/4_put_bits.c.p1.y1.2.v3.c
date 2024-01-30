Variant 1:

static void put_bits(Jpeg2000EncoderContext *s, int val, int n)
{
    int i = 0;
    while (i < n){
        if (s->bit_index == 8)
        {
            s->bit_index = *s->buf == 0xff ? 1 : 0;
            *(++s->buf) = 0;
        }
        *s->buf |= val << (7 - (s->bit_index++));
        i++;
    }
}


Variant 2:

static void put_bits(Jpeg2000EncoderContext *s, int val, int n)
{
    for(int i=0; i<n; i++) {
        if (s->bit_index == 8) {
            s->bit_index = *s->buf == 0xff;
            *(++s->buf) = 0;
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
            s->bit_index = *s->buf == 0xff;
            *(++s->buf) = 0;
        }
        *s->buf |= val << (7 - (s->bit_index++));
    } while(--n > 0);
}
 NotImplementedInReferenceCode