Version 1: Factors out an equivalent expression.

static void put_bits(Jpeg2000EncoderContext *s, int val, int n) 
{
    int factor;
    while (n-- > 0){
        if (s->bit_index == 8)
        {
            s->bit_index = *s->buf == 0xff;
            *(++s->buf) = 0;
        }
        factor = 7 - s->bit_index++;
        *s->buf |= val << factor;
    }
}

Version 2: Reverses conditions. 

static void put_bits(Jpeg2000EncoderContext *s, int val, int n) 
{
    while (n-- > 0){
        if (s->bit_index != 8) 
        {   
            *s->buf |= val << (7 - s->bit_index++);
        }
        else
        {   
            s->bit_index = *s->buf == 0xff;
            *(++s->buf) = 0;
            *s->buf |= val << (7 - s->bit_index++);
        }
    }
}

Version 3: Flattens nested conditions.

static void put_bits(Jpeg2000EncoderContext *s, int val, int n) 
{
    while (n--) 
    {
        if (s->bit_index == 8 && *s->buf == 0xff)
        {
            s->bit_index = 1;
            *(++s->buf) = 0;
            *s->buf |= val << (7 - s->bit_index++);
        } 
        else if (s->bit_index == 8)
        {
            s->bit_index = 0;
            *(++s->buf) = 0;
        } 
        else
        {
            *s->buf |= val << (7 - s->bit_index++);
        }
    }
}