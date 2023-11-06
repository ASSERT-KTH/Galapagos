1. Using For Loop:

static void put_bits(Jpeg2000EncoderContext *s, int val, int n)
{
    for(int i = 0; i < n; i++){
        if (s->bit_index == 8)
        {
            s->bit_index = *s->buf == 0xff;
            *(++s->buf) = 0;
        }
        *s->buf |= val << (7 - s->bit_index++);
    }
}


2. Using Do-While loop:
++
static void put_bits(Jpeg2000EncoderContext *s, int val, int n)
{
    do {
        if (s->bit_index == 8)
        {
            s->bit_index = *s->buf == 0xff;
            *(++s->buf) = 0;
        }
        *s->buf |= val << (7 - s->bit_index++);
    } while (--n > 0);
}


Three index based method instead of a pointer:


static void put_bits(Jpeg2000EncoderContext *s, int val, int n)
{
    int index = 0;
    while (n-- > 0){
        if (s->bit_index == 8)
        {
            s->bit_index = s->buf[index] == 0xff;
            s->buf[++index] = 0;
        }
        s->buf[index] |= val << (7 - s->bit_index++);
    }
}


4. Using Ternary operator instead of `if` condition:


static void put_bits(Jpeg2000EncoderContext *s, int val, int n)
{
    while (n-- > 0){
        s->bit_index = (s->bit_index == 8) ? ((*s->buf == 0xff) , (*(++s->buf) = 0)) : s->bit_index;
        *s->buf |= val << (7 - s->bit_index++);
    }
}
