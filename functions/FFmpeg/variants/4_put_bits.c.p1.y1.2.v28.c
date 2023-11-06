Variant 1:

static void put_bits(Jpeg2000EncoderContext *s, int val, int n)
{
    do {
        if (8 == s->bit_index) {
          s->bit_index = (*s->buf == 0xff) ? 1 : 0;
          *++s->buf = 0;
        }
        *s->buf |= (val << (7 - s->bit_index++));
    } while (--n > 0);
}


Variant 2:

static void put_bits(Jpeg2000EncoderContext *s, int val, int n)
{
    for (; n > 0; n--) {
        s->bit_index = (s->bit_index == 8) ? ((*s->buf == 0xff) ?  1 : 0) : s->bit_index;
        s->buf = (s->bit_index == 8) ? (++s->buf) : s->buf;
        if (s->bit_index == 8)
            *s->buf = 0;

        *s->buf |= (val << (7 - (s->bit_index)));
        ++(s->bit_index);
    }
}


Variant 3:
This version adds temporal variables for readability.

static void put_bits(Jpeg2000EncoderContext *s, int val, int n)
{
    while (n > 0) {
        int* bit_buf = s->buf;
        unsigned char bit_index = s->bit_index;

        bit_index = (bit_index == 8) ? ( (*bit_buf == 0xff) ?  1 : 0) : bit_index;
        bit_buf = (bit_index == 8) ? (++s->buf) : bit_buf;
        
        if (bit_index == 8) *bit_buf = 0;
        
        *bit_buf |= (val << (7 - bit_index));
        bit_index++;

        s->bit_index = bit_index;
        n--;
    }
}
