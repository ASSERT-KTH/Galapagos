
static void put_bits(Jpeg2000EncoderContext *s, int val, int n) // Variant A 
{
    for (; n > 0 ; n--) {
        if (s->bit_index == 8)
        {
            s->bit_index = *s->buf == 0xff? 1 : 0;             
            s->buf = s->buf + 1; // same as ++s->buf
            *s->buf = 0;
        }
        *s->buf |= val << (7 - s->bit_index);
        s->bit_index++; //same as s->bit_index++
    }
}


static void put_bits(Jpeg2000EncoderContext *s, int val, int n) // Variant B
{
    while (n > 0){
        if (s->bit_index == 8)
        {
            if (*s->buf == 0xff){
                s->bit_index = 1;
            } else {
                s->bit_index = 0;
            }
            *(s->buf++) = 0; // Postfix increment inside the brackets.
        }
        *(s->buf) = *(s->buf) | (val << (7 - s->bit_index));
        s->bit_index += 1; //Equivalent to s->bit_index++
        n--; // Explicit decrement at the end of the loop
    }
}
