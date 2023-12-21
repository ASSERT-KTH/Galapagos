
/*
Function variant #1: For-loop variant
Exchanging the control structure 'while' with 'for'
 */
static void put_bits(Jpeg2000EncoderContext *s, int val, int n) // TODO: optimize
{
    for(; n > 0; n--){
        if (s->bit_index == 8)
        {
            s->bit_index = *s->buf == 0xff;
            *(++s->buf) = 0;
        }
        *s->buf |= val << (7 - s->bit_index++);
    }
}

/*
Function variant #2: Bit manipulation variant
Using bitwise operator '>>=' instead of division by 2
 */
static void put_bits(Jpeg2000EncoderContext *s, int val, int n) // TODO: optimize
{
    while (n-- > 0){
        if (s->bit_index == 8)
        {
            s->bit_index = *s->buf == 0xff;
            *(++s->buf) = 0;
        }
        *s->buf |= val << (7 - s->bit_index);
        val >>= 1;
    }
}

/*
Function variant #3: Ternary operator variant
Using ternary operator instead of if statement.
 */
static void put_bits(Jpeg2000EncoderContext *s, int val, int n) // TODO: optimize
{
    while (n-- > 0){
        s->bit_index = s->bit_index == 8 ? (*s->buf == 0xff) : s->bit_index;
        *s->buf = s->bit_index == 8 ? (*(++s->buf) = 0) : *s->buf;
        *s->buf |= val << (7 - s->bit_index++);
    }
}

