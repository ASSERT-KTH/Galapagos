1. Change while loop into for loop

static void put_bits(Jpeg2000EncoderContext *s, int val, int n) 
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


2. Use ternary operator instead of if statement

static void put_bits(Jpeg2000EncoderContext *s, int val, int n) 
{
    while (n-- > 0) {
        s->bit_index = (s->bit_index == 8) ? (*s->buf == 0xff) : s->bit_index; 
        if (s->bit_index == 1) 
            *(++s->buf) = 0;
        *s->buf |= val << (7 - s->bit_index++);
    }
}
 

3. Use do-while loop instead of while loop 

static void put_bits(Jpeg2000EncoderContext *s, int val, int n) 
{
    do {
        if (s->bit_index == 8)
        {
            s->bit_index = *s->buf == 0xff;
            *(++s->buf) = 0;
        }
        *s->buf |= val << (7 - s->bit_index++);
    } while(--n > 0);
}

4. Giving n-- command separately

static void put_bits(Jpeg2000EncoderContext *s, int val, int n) 
{
    while (n > 0){
        if (s->bit_index == 8)
        {
            s->bit_index = *s->buf == 0xff;
            *(++s->buf) = 0;
        }
        *s->buf |= val << (7 - s->bit_index++);
        n--;
    }
}

